#ifndef __MY_UART_H__
#define __MY_UART_H__

#include "cms8s6990.h"

/*****************************************************************************/
/* UART0 配置参数                                                            */
/*****************************************************************************/
/**
 ** UART0 通信波特率（bps）
 ** 用于 USE_FORMULA 分支，由 UART_ConfigBaudRate() 自动计算重装值
 */
#define MY_UART_BAUD_RATE        (9600UL)

/**
 ** BRT（波特率定时器）16 位重装初值，写入 BRTH:BRTL
 ** 计算依据：SystemClock = 48MHz，SMOD = 2（倍频使能），BRT 分频 = 1
 **   BRTValue = 65536 - (48MHz * 2) / (32 * 1 * 9600) = 65536 - 312.5 ≈ 65224 = 0xFEC8
 ** 实际重装计数 = 65536 - 65224 = 312，对应波特率 ≈ 9615bps（偏差 +0.16%）
 ** 注意：修改系统时钟或波特率后，此常量必须重新计算
 */
#define MY_UART_BRT_PERIOD       (0xFEC8U)

/* UART0 发送引脚：P2.4，复用为 TXD0 */
#define MY_UART_TX_PIN           (P24CFG)

/* UART0 接收引脚：P2.5，复用为 RXD0 */
#define MY_UART_RX_PIN           (P25CFG)

/*****************************************************************************/
/* 函数声明                                                                  */
/*****************************************************************************/
/**
 ** \brief 初始化 UART0（8 位异步、BRT 波特率、中断收发）
 ** \param 无
 ** \return 无
 */
void UART0_Config(void);

/**
 ** \brief UART0 中断处理任务，需在中断服务程序中调用
 **        接收中断时将收到的字节原样回发（echo）
 ** \param 无
 ** \return 无
 */
void UART0_IRQHandler_Task(void);

#endif /* __MY_UART_H__ */
