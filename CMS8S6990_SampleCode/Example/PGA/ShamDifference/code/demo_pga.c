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
/** \file demo_pga.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_pga.h"

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
 ** \brief	 PGA_Config
 ** \param [in] 
 **           
 ** \return  none
 ** \note  
 ******************************************************************************/
void PGA_Config(void)
{
	
	/*
	(1)设置PGA运行模式
	*/
	PGA_EnableNormalMode(PGA_NORM_SHAM_DIFFERENCE);		//差分模式
	/*
	(2)设置PGA的信号输入
	*/
	PGA_ConfigInput(PGA_DIF_H_PGAP_L_PGAGND);	
	/*
	(3)设置PGA的放大增益
	*/
	PGA_ConfigGain(PGA_GAIN_4);
	/*
	(4)设置PGA的采样保持
	*/	
	PGA_DisableSHA();

	/*
	(5)设置PGA的输出
	*/		
	PGA_EnableOutput();
	
	/*
	(6)设置PGA的IO口
	*/		
	GPIO_SET_MUX_MODE(P31CFG,GPIO_P31_MUX_PGAP);
	GPIO_SET_MUX_MODE(P32CFG,GPIO_P32_MUX_PGAGND);	
	
	GPIO_SET_MUX_MODE(P26CFG,GPIO_P26_MUX_PGAO);	
	/*
	(7)开启PGA
	*/	
	PGA_Start();
}



























