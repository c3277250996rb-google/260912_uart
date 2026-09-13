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
/** \file demo_timer.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "demo_epwm.h"

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


/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/

/******************************************************************************
** \brief	 EPWM_Config (complementary, no dead time)
** \param [in] 
**            	
** \return  none
** \note  
******************************************************************************/
void EPWM_Config(void)
{
	//设置EPWM运行模式
	EPWM_ConfigRunMode(EPWM_WFG_COMPLEMENTARY|EPWM_OC_INDEPENDENT|EPWM_OCU_SYMMETRIC|EPWM_COUNT_UP_DOWN); //互补模式+输出独立模式+对称计数模式+上下计数(中心对齐)模式
	//设置EPWM运行时钟	
	EPWM_ConfigChannelClk(EPWM0, EPWM_CLK_DIV_1);		
	EPWM_ConfigChannelClk(EPWM2, EPWM_CLK_DIV_1);
	EPWM_ConfigChannelClk(EPWM4, EPWM_CLK_DIV_1);
	//设置EPWM 周期以及占空比	
	EPWM_ConfigChannelPeriod(EPWM0, 0x12C0);
	EPWM_ConfigChannelPeriod(EPWM2, 0x12C0);
	EPWM_ConfigChannelPeriod(EPWM4, 0x12C0);

	#if (1)
	EPWM_ConfigChannelSymDuty(EPWM0, 0x0960);
	EPWM_ConfigChannelSymDuty(EPWM2, 0x0960);
	EPWM_ConfigChannelSymDuty(EPWM4, 0x0960);
	#elif (0)
	EPWM_ConfigChannelSymDuty(EPWM0, 0);
	EPWM_ConfigChannelSymDuty(EPWM2, 0);
	EPWM_ConfigChannelSymDuty(EPWM4, 0);
	#else 
	EPWM_ConfigChannelSymDuty(EPWM0, 0xFFFF);
	EPWM_ConfigChannelSymDuty(EPWM2, 0xFFFF);
	EPWM_ConfigChannelSymDuty(EPWM4, 0xFFFF);
	#endif

	//设置EPWM的加载方式为自动加载
	EPWM_EnableAutoLoadMode(EPWM_CH_4_MSK|EPWM_CH_2_MSK|EPWM_CH_0_MSK);
	//设置EPWM的输出极性
	EPWM_DisableReverseOutput(EPWM_CH_0_MSK|EPWM_CH_1_MSK|EPWM_CH_2_MSK|EPWM_CH_3_MSK|EPWM_CH_4_MSK|EPWM_CH_5_MSK); //关闭反向输出
	//设置EPWM输出
	EPWM_EnableOutput(EPWM_CH_0_MSK|EPWM_CH_1_MSK|EPWM_CH_2_MSK|EPWM_CH_3_MSK|EPWM_CH_4_MSK|EPWM_CH_5_MSK);		//开启输出
	//设置EPWM死区
	EPWM_DisableDeadZone(EPWM0);
	EPWM_DisableDeadZone(EPWM2);
	EPWM_DisableDeadZone(EPWM4);
	//设置EPWM中断
	EPWM_EnableZeroInt(EPWM_CH_0_MSK);				//开启EPWM零点中断
	EPWM_AllIntEnable();							//开启EPWM总中断
	IRQ_SET_PRIORITY(IRQ_PWM,IRQ_PRIORITY_HIGH);
	IRQ_ALL_ENABLE();								//开启总中断

	//设置EPWM输出IO复用
	GPIO_SET_MUX_MODE(P13CFG, GPIO_MUX_PG0);
	GPIO_SET_MUX_MODE(P14CFG, GPIO_MUX_PG1);
	GPIO_SET_MUX_MODE(P15CFG, GPIO_MUX_PG2);
	GPIO_SET_MUX_MODE(P16CFG, GPIO_MUX_PG3);
	GPIO_SET_MUX_MODE(P17CFG, GPIO_MUX_PG4);
	GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_PG5);
	//开启EPWM
	EPWM_Start(EPWM_CH_4_MSK|EPWM_CH_2_MSK|EPWM_CH_0_MSK);
}


