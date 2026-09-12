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
#include "demo_wut.h"
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

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/
void GPIO_SetPowerSavingMode(void);

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	 main
 **
 ** \param [in]  none   
 **
 ** \return 0
 ** \note 关闭调试功能，功耗会更低 
 *****************************************************************************/

int main(void)
{		
	uint8_t i,j;
	//休眠前先设置GPIO,关闭外设耗电
	GPIO_SetPowerSavingMode();
	//不使用展示口功耗会更低		
	GPIO_SET_MUX_MODE(P24CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_4);
	P24 =0;										
	GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_GPIO);
	GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_5);
	P25 =0;										

	WUT_Config();
		
	SYS_EnableWakeUp();

	while(1)
	{	
		for(i=250;i>0;i--)					//P25翻转一段时间进入休眠，WUT定时时间到后唤醒芯片
		{
			P25 = ~P25;
			for(j=250;j>0;j--);		
		}
		SYS_EnterStop();
	}		
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





















