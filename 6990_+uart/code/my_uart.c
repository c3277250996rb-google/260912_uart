#include "my_uart.h"

void UART0_Config(void)
{
	uint16_t BRTValue = 0;

	UART_ConfigRunMode(UART0, UART_MOD_ASY_8BIT, UART_BAUD_BRT);
	UART_EnableReceive(UART0);
	UART_ConfigBRTClk(BRT_CLK_DIV_1);
	UART_EnableDoubleFrequency(UART0);

#ifdef USE_FORMULA
	BRTValue = UART_ConfigBaudRate(UART0, MY_UART_BAUD_RATE);
#else
	BRTValue = MY_UART_BRT_PERIOD;
#endif

	UART_ConfigBRTPeriod(BRTValue);
	UART_EnableBRT();

	GPIO_SET_MUX_MODE(MY_UART_TX_PIN, GPIO_MUX_TXD0);
	GPIO_SET_MUX_MODE(MY_UART_RX_PIN, GPIO_MUX_RXD0);

	UART_EnableInt(UART0);
	IRQ_SET_PRIORITY(IRQ_UART0, IRQ_PRIORITY_LOW);
	IRQ_ALL_ENABLE();
}

void UART0_IRQHandler_Task(void)
{
	if(UART_GetSendIntFlag(UART0))
	{
		UART_ClearSendIntFlag(UART0);
	}
	if(UART_GetReceiveIntFlag(UART0))
	{
		UART_SendBuff(UART0, UART_GetBuff(UART0));
		UART_ClearReceiveIntFlag(UART0);
	}
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
