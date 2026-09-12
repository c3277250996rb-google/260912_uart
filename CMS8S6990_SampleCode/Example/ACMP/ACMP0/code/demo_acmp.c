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
/** \file demo_acmp.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_acmp.h"

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

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/
/******************************************************************************
 ** \brief	 ACMP0_Config
 ** \param [in] 
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void ACMP0_Config(void)
{
#define NULL  0
	
	/*
	(1)设置ACMP正端输入
	*/
	ACMP_ConfigPositive(ACMP0, ACMP_POSSEL_P0);
	/*
	(2)设置ACMP负端输入
	*/
	ACMP_ConfigNegative(ACMP0, ACMP_NEGSEL_CN,0);
	/*
	(3)设置输出相位
	*/
	ACMP_DisableReverseOutput(ACMP0);		
	/*
	(4)设置输出滤波
	*/
	ACMP_EnableFilter(ACMP0,ACMP_NFCLK_3_TSYS);	
	/*
	(5)设置输出迟滞
	*/	
	ACMP_EnableHYS(ACMP0,ACMP_HYS_SEL_P,ACMP_HYS_10);
	
	/*
	(6)设置中断
	*/		
	ACMP_EnableInt(ACMP0);								//开启ACMP0中断
	IRQ_SET_PRIORITY(IRQ_ACMP, IRQ_PRIORITY_LOW);		//设置中断优先级
	IRQ_ALL_ENABLE();									//开启总中断
		
	/*
	(7)设置ACMP IO
	*/		
	GPIO_SET_MUX_MODE(P13CFG, GPIO_P13_MUX_C0P0);		//设置正端输入
//	GPIO_SET_MUX_MODE(P00CFG, GPIO_P00_MUX_C0P1);	
//	GPIO_SET_MUX_MODE(P01CFG, GPIO_P01_MUX_C0P2);		
//	GPIO_SET_MUX_MODE(P30CFG, GPIO_P30_MUX_C0P4);		
//	GPIO_SET_MUX_MODE(P24CFG, GPIO_P24_MUX_C0P5);	

	GPIO_SET_MUX_MODE(P14CFG, GPIO_P14_MUX_C0N);		//设置负端输入
	
	GPIO_SET_MUX_MODE(P15CFG, GPIO_MUX_C0O);			//设置输出

	/*
	(8)开启ACMP
	*/		
	ACMP_Start(ACMP0);

}



