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
/** \file demo_spi.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_spi.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
****************************************************************************/


/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
****************************************************************************/

/*****************************************************************************
 ** \brief	SPI_Transmit
 **			
** \param [in] SendData: 发送的值
 ** \return  16bit 获取的值
 ** \note	
*****************************************************************************/
uint8_t  SPI_Transmit(uint8_t  Data)
{	
	SPDR = Data;
	while(!SPI_GetTransferIntFlag());
	return (SPDR);				
}
/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/
/******************************************************************************
 ** \brief	 SPI_Config
 ** \param [in] 
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void SPI_Config(void)
{
	/*
	(1)设置SPI时钟
	*/
	SPI_ConfigClk(SPI_CLK_DIV_8);									/*设置时钟*/
	/*
	(2)设置SPI运行模式
	*/
	SPI_ConfigRunMode(SPI_CLK_CPOL_LOW, SPI_CLK_CPHA_0, SPI_NSS_SSCR_CONTROL);/*设置SPI 空闲时时钟为低电平、相位选择CPHA = 0 */
																	/*设置SPI NSSx信号受SSCR中的内容控制*/																							
	/*
	(3)设置IO口复用
	*/
	GPIO_SET_MUX_MODE(P15CFG,GPIO_MUX_SCLK);		/*SCLK*/
	GPIO_SET_MUX_MODE(P17CFG,GPIO_MUX_MISO);		/*MISO*/
	GPIO_SET_MUX_MODE(P16CFG,GPIO_MUX_MOSI);		/*MOSI*/
	GPIO_SET_MUX_MODE(P36CFG,GPIO_MUX_NSS);		/*CS*/	
	
	/*
	(4)开启SPI主控or从机模式
	*/
	SPI_EnableSlaveMode();	
	
		/*
	(5)设置中断方式
	*/
	SPI_EnableIntFlag();
	/*
	(6)设置中断优先级
	*/
	IRQ_SET_PRIORITY(IRQ_SPI, IRQ_PRIORITY_LOW);
	/*
	(7)开启总中断
	*/	
	IRQ_ALL_ENABLE();	
	
	/*
	(8)开启SPI
	*/
	SPI_Start();
}









