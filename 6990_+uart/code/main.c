#include "cms8s6990.h"
#include "system.h"
#include "my_uart.h"
#include "my_timer.h"
#include "stdio.h"


uint32_t Systemclock = MY_SYSTEM_CLOCK_HZ;



int main(void)
{
	SYS_SET_SYSTEM_CLK(SYS_CLK_DIV_1);
	Timer0_Config();
	UART0_Config();
	printf("UART ready\r\n");

	while(1)
	{	
		uint32_t seconds = 0;

		if(Timer0_GetPendingSeconds(&seconds))
		{
			printf("Uptime: %lu s\r\n", seconds);
		}
	}		
}




















