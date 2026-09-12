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
/** \file demo_gpio.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_gpio.h"

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
 ** \brief	 GPIO_Config
 ** \param [in] none
 **          GPIO中断功能
 ** \return  none
 ** \note  
 ******************************************************************************/
void GPIO_Config(void)
{
	/*
	(1)设置P23 IO功能
	*/
	GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_GPIO);		//设置P23为GPIO模式
	GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_3);			//设置为输入模式
	GPIO_ENABLE_RD(P2RD, GPIO_PIN_3);				//开启下拉
	/*
	(2)设置中断方式
	*/
	GPIO_SET_INT_MODE(P23EICFG, GPIO_INT_FALLING);	//设置为下降沿中断模式
	GPIO_EnableInt(GPIO2, GPIO_PIN_3_MSK);			//开启P23中断
	/*
	(3)设置中断优先级
	*/
	IRQ_SET_PRIORITY(IRQ_P2, IRQ_PRIORITY_LOW);
	/*
	(4)开启总中断
	*/	
	IRQ_ALL_ENABLE();

	
}

/******************************************************************************
 ** \brief	 GPIO_SetPowerSavingMode
 **       GPIO关闭耗电
 ** \param [in] none   	
 ** \return  none
 ** \note 悬空/未使用/未封装的管脚需要配置为输出，并配置固定电平。  
 ******************************************************************************/
void GPIO_SetPowerSavingMode(void)
{	
	GPIO_SET_MUX_MODE(P00CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_0);		//P00
	GPIO_SET_MUX_MODE(P01CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_1);		//P01
	GPIO_SET_MUX_MODE(P02CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_2);		//P02
	GPIO_SET_MUX_MODE(P03CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_3);		//P03
	GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_4);		//P04
	GPIO_SET_MUX_MODE(P05CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_5);		//P05	
	P0 =0;
	
	GPIO_SET_MUX_MODE(P13CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_3);		//P13
	GPIO_SET_MUX_MODE(P14CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_4);		//P14
	GPIO_SET_MUX_MODE(P15CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_5);		//P15
	GPIO_SET_MUX_MODE(P16CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_6);		//P16
	GPIO_SET_MUX_MODE(P17CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_7);		//P17
	P1 =0;
	
	GPIO_SET_MUX_MODE(P21CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_1);		//P21
	GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_2);		//P22
	GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_3);		//P23
	GPIO_SET_MUX_MODE(P24CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_4);		//P24
	GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_5);		//P25
	GPIO_SET_MUX_MODE(P26CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_6);		//P26
	P2 =0;
	
	GPIO_SET_MUX_MODE(P30CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_0);		//P30
	GPIO_SET_MUX_MODE(P31CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_1);		//P31
	GPIO_SET_MUX_MODE(P32CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_2);		//P32
	GPIO_SET_MUX_MODE(P35CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_5);		//P35
	GPIO_SET_MUX_MODE(P36CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P3TRIS, GPIO_PIN_6);		//P36
	P3 =0;
	
}





















