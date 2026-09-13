#include "cms8s6990.h"
#include "my_timer.h"
#include "my_uart.h"

void Timer0_IRQHandler(void) interrupt TMR0_VECTOR
{
	Timer0_IRQHandler_Task();
}

void UART0_IRQHandler(void) interrupt UART0_VECTOR
{
	UART0_IRQHandler_Task();
}
