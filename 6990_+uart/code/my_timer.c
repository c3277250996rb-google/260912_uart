#include "my_timer.h"
#include "timer.h"
#include "stdio.h"

/* Millisecond counter, incremented by the Timer0 overflow ISR. */
static volatile uint16_t timer0_ms;

/* Whole seconds elapsed since Timer0_Config() was called. */
static volatile uint32_t uptime_seconds;

/* Set by the ISR when a full second elapsed, cleared by the getter. */
static volatile uint8_t uptime_second_pending;

void Timer0_Config(void)
{
	/* 16-bit timer in timing (interval) mode. */
	TMR_ConfigRunMode(TMR0, TMR_MODE_TIMING, TMR_TIM_16BIT);

	/* Pre-scale the timer clock to Fsys / 12 = 4 MHz. */
	TMR_ConfigTimerClk(TMR0, TMR_CLK_DIV_12);

	/* Load the 1 ms period into the period registers. */
	TMR_ConfigTimerPeriod(TMR0, MY_TIMER0_RELOAD_HIGH, MY_TIMER0_RELOAD_LOW);

	/* Drop any stale overflow flag before enabling the interrupt. */
	TMR_ClearOverflowIntFlag(TMR0);
	TMR_EnableOverflowInt(TMR0);
	IRQ_SET_PRIORITY(IRQ_TMR0, IRQ_PRIORITY_LOW);

	/* Start the counter. Global interrupts are enabled by the caller. */
	TMR_Start(TMR0);
}

void Timer0_IRQHandler_Task(void)
{
	/* 16-bit mode is not auto-reload: load the period again each time,
	 * then clear the overflow flag (TF0). */
	TMR0_SET_PERIOD(MY_TIMER0_RELOAD_HIGH, MY_TIMER0_RELOAD_LOW);
	TF0 = 0;

	/* Accumulate 1000 ticks of 1 ms into one whole second. */
	if(++timer0_ms >= MY_TIMER0_MS_PER_SECOND)
	{
		timer0_ms = 0;
		++uptime_seconds;
		uptime_second_pending = 1;
	}
}

uint8_t Timer0_GetPendingSeconds(uint32_t *seconds)
{
	uint8_t pending = 0;

	/* uptime_seconds is 32 bits, so read and clear it atomically with
	 * respect to the ISR by disabling interrupts around the access. */
	IRQ_ALL_DISABLE();
	if(uptime_second_pending)
	{
		*seconds = uptime_seconds;
		uptime_second_pending = 0;
		pending = 1;
	}
	IRQ_ALL_ENABLE();

	return pending;
}

void Timer0_PrintUptime(void)
{
	uint32_t seconds = 0;

	/* Print only when a new second elapsed, not on every loop pass. */
	if(Timer0_GetPendingSeconds(&seconds))
	{
		printf("Uptime: %lu s\r\n", seconds);
	}
}
