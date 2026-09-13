#include "my_timer.h"
#include "timer.h"

static volatile uint16_t timer0_ms;
static volatile uint32_t uptime_seconds;
static volatile uint8_t uptime_second_pending;

void Timer0_Config(void)
{
	TMR_ConfigRunMode(TMR0, TMR_MODE_TIMING, TMR_TIM_16BIT);
	TMR_ConfigTimerClk(TMR0, TMR_CLK_DIV_12);
	TMR_ConfigTimerPeriod(TMR0, MY_TIMER0_RELOAD_HIGH, MY_TIMER0_RELOAD_LOW);
	TMR_ClearOverflowIntFlag(TMR0);
	TMR_EnableOverflowInt(TMR0);
	IRQ_SET_PRIORITY(IRQ_TMR0, IRQ_PRIORITY_LOW);
	TMR_Start(TMR0);
}

void Timer0_IRQHandler_Task(void)
{
	TMR0_SET_PERIOD(MY_TIMER0_RELOAD_HIGH, MY_TIMER0_RELOAD_LOW);
	TF0 = 0;

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
