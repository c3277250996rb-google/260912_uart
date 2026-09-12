#include "demo_uart.h"

void UART0_Config(void)
{
	uint16_t BRTValue = 0;
	uint32_t BaudRateValue = 9600;

	UART_ConfigRunMode(UART0, UART_MOD_ASY_8BIT, UART_BAUD_BRT);
	UART_EnableReceive(UART0);
	UART_ConfigBRTClk(BRT_CLK_DIV_1);
	UART_EnableDoubleFrequency(UART0);

#ifdef USE_FORMULA
	BRTValue = UART_ConfigBaudRate(UART0, BaudRateValue);
#else
	BRTValue = 65380;
#endif

	UART_ConfigBRTPeriod(BRTValue);
	UART_EnableBRT();

	GPIO_SET_MUX_MODE(P24CFG, GPIO_MUX_TXD0);
	GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_RXD0);

	UART_EnableInt(UART0);
	IRQ_SET_PRIORITY(IRQ_UART0, IRQ_PRIORITY_LOW);
	IRQ_ALL_ENABLE();
}
