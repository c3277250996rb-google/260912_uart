#ifndef __MY_TIMER_H__
#define __MY_TIMER_H__

#include "cms8s6990.h"

#define MY_SYSTEM_CLOCK_HZ       (48000000UL)
#define MY_TIMER0_TICK_HZ        (1000UL)
#define MY_TIMER0_CLOCK_DIV      (12UL)
#define MY_TIMER0_RELOAD_VALUE   (65536UL - (MY_SYSTEM_CLOCK_HZ / \
                                           MY_TIMER0_CLOCK_DIV / \
                                           MY_TIMER0_TICK_HZ))
#define MY_TIMER0_RELOAD_HIGH    ((uint8_t)(MY_TIMER0_RELOAD_VALUE >> 8))
#define MY_TIMER0_RELOAD_LOW     ((uint8_t)MY_TIMER0_RELOAD_VALUE)
#define MY_TIMER0_MS_PER_SECOND  (1000U)

void Timer0_Config(void);
void Timer0_IRQHandler_Task(void);
uint8_t Timer0_GetPendingSeconds(uint32_t *seconds);

#endif /* __MY_TIMER_H__ */
