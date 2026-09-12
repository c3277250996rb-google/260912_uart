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
/** \file demo_opa.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_opa.h"

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
 ** \brief	 OPA0_Config
 ** \param [in] 
 **            	
 ** \return  none
 ** \note  
 ******************************************************************************/
void OPA0_Config(void)
{
	/*
	(1)设置OPA的运行模式
	*/
	OPA_SetRunMode(OPA0, OPA_MODE_OPA);
	/*
	(2)设置OPA的正端输入
	*/
	OPA_ConfigPositive(OPA0, OPA_POSSEL_P);
	/*
	(3)设置OPA的负端输入
	*/
	OPA_ConfigNegative(OPA0, OPA_NEGSEL_N);	
	/*
	(4)设置OPA的输出
	*/
	OPA_EnableOutput(OPA0);
	/*
	(5)设置OPA端口
	*/
	GPIO_SET_MUX_MODE(P31CFG,GPIO_P31_MUX_OP0N);
	GPIO_SET_MUX_MODE(P32CFG,GPIO_P32_MUX_OP0P);
	GPIO_SET_MUX_MODE(P30CFG,GPIO_P30_MUX_OP0O);	
	/*
	(6)开启OPA
	*/	
	OPA_Start(OPA0);
}























