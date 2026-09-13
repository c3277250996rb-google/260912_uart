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

char putchar(char ch)
{
	uint8_t uart0_int_enabled = ES0;

	ES0 = 0;
	SCON0 &= ~(UART_SCON0_TI0_Msk);
	SBUF0 = ch;
	while(!(SCON0 & UART_SCON0_TI0_Msk))
	{
		;
	}
	SCON0 &= ~(UART_SCON0_TI0_Msk);
	ES0 = uart0_int_enabled;

	return ch;
}

char getchar(void)
{
	uint8_t uart0_int_enabled = ES0;
	char ch;

	ES0 = 0;
	while(!(SCON0 & UART_SCON0_RI0_Msk))
	{
		;
	}
	ch = SBUF0;
	SCON0 &= ~(UART_SCON0_RI0_Msk);
	ES0 = uart0_int_enabled;

	return ch;
}

int puts(const char *s)
{
	while(*s)
	{
		putchar(*s++);
	}

	return 0;
}
