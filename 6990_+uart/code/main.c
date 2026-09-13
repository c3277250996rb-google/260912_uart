#include "cms8s6990.h"
#include "my_uart.h"


uint32_t Systemclock = 24000000;
volatile uint16_t timer0_ms = 0;
volatile uint32_t uptime_seconds = 0;
volatile uint8_t uptime_second_pending = 0;



int main(void)
{	
	Timer0_Config();
	UART0_Config();
	printf("UART ready\r\n");

	while(1)
	{	
		uint8_t print_uptime = 0;
		uint32_t seconds = 0;

		IRQ_ALL_DISABLE();
		if(uptime_second_pending)
		{
			seconds = uptime_seconds;
			uptime_second_pending = 0;
			print_uptime = 1;
		}
		IRQ_ALL_ENABLE();

		if(print_uptime)
		{
			printf("Uptime: %lu s\r\n", seconds);
		}
	}		
}






















