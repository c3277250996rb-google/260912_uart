#ifndef __MY_UART_H__
#define __MY_UART_H__

#include "cms8s6990.h"

#if 1	/* UART0 console (base feature). */
/* UART0 baud rate in bps. */
#define MY_UART_BAUD_RATE        (9600UL)

/* BRT reload value for 48 MHz / 9600 bps with SMOD = 1:
 * 65536 - (48 MHz * 2) / (32 * 9600) = 0xFEC8 (~9615 bps, +0.16%).
 * Recalculate when the system clock or baud rate changes. */
#define MY_UART_BRT_PERIOD       (0xFEC8U)

/* TXD0 / RXD0 pin config registers (function is remappable). */
#define MY_UART_TX_PIN           (P24CFG)
#define MY_UART_RX_PIN           (P25CFG)

/* Initialize UART0: 8-bit async, BRT baud timer, RX interrupt, pin mux. */
void UART0_Config(void);

/* UART0 ISR task: clear TX flag, echo received bytes. */
void UART0_IRQHandler_Task(void);
	/* UART0 console */

#endif


#endif /* __MY_UART_H__ */
