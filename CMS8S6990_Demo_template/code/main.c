/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/****************************************************************************/
/** \file main.c
**
** 
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms8s6990.h"
#include "demo_uart.h"
#include "timer.h"
#include "stdio.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/


/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/
uint32_t Systemclock = 24000000;
volatile uint16_t timer0_ms = 0;
volatile uint32_t uptime_seconds = 0;
volatile uint8_t uptime_second_pending = 0;

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/


/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

static void Timer0_Config(void)
{
	/* 24 MHz / 12 = 2 MHz; 2000 counts produce a 1 ms interrupt. */
	TMR_ConfigRunMode(TMR0, TMR_MODE_TIMING, TMR_TIM_16BIT);
	TMR_ConfigTimerClk(TMR0, TMR_CLK_DIV_12);
	TMR_ConfigTimerPeriod(TMR0, 0xF8, 0x30);
	TMR_ClearOverflowIntFlag(TMR0);
	TMR_EnableOverflowInt(TMR0);
	IRQ_SET_PRIORITY(IRQ_TMR0, IRQ_PRIORITY_LOW);
	TMR_Start(TMR0);
}

/*****************************************************************************
 ** \brief	 main
 **
 ** \param [in]  none   
 **
 ** \return 0
 *****************************************************************************/

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


















