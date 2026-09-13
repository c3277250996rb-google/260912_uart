#ifndef __MY_TIMER_H__
#define __MY_TIMER_H__

#include "cms8s6990.h"

#if 1	/* Timer0 tick and uptime report (base feature). */
/* System clock: 48 MHz, divider = 1. */
#define MY_SYSTEM_CLOCK_HZ       (48000000UL)

/* Timer0 tick: 1 kHz (1 ms), counter clocked at Fsys / 12 = 4 MHz. */
#define MY_TIMER0_TICK_HZ        (1000UL)
#define MY_TIMER0_CLOCK_DIV      (12UL)

/* 16-bit reload for a 1 ms period: 65536 - 48 MHz / 12 / 1000 = 0xF060. */
#define MY_TIMER0_RELOAD_VALUE   (65536UL - (MY_SYSTEM_CLOCK_HZ / \
                                           MY_TIMER0_CLOCK_DIV / \
                                           MY_TIMER0_TICK_HZ))

/* Reload value as TH0 / TL0. */
#define MY_TIMER0_RELOAD_HIGH    ((uint8_t)(MY_TIMER0_RELOAD_VALUE >> 8))
#define MY_TIMER0_RELOAD_LOW     ((uint8_t)MY_TIMER0_RELOAD_VALUE)

/* 1 ms ticks per second. */
#define MY_TIMER0_MS_PER_SECOND  (1000U)

/* Start Timer0 (16-bit timing, 1 ms). Caller enables global interrupts. */
void Timer0_Config(void);

/* Timer0 ISR task: reload period, clear TF0, count ms and seconds. */
void Timer0_IRQHandler_Task(void);

/* Get elapsed seconds; returns 1 if a new second was pending, else 0. */
uint8_t Timer0_GetPendingSeconds(uint32_t *seconds);

/* Print the uptime once per elapsed second. Call from the main loop. */
void Timer0_PrintUptime(void);
	/* Timer0 tick and uptime report */

#endif


#endif /* __MY_TIMER_H__ */
