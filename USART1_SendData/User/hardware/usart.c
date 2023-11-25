#include "usart.h"
#include "stm32f10x.h"                  // Device header

void USART_Configuartion(void)
{
		
		USART_InitTypeDef USART_InitStructure;
	
		/* 打开串口的时钟 */
		// 不用打开复用时钟，只有重映射和外部中断需要复用时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
		
	  /* 串口模式的配置 */
		USART_InitStructure.USART_BaudRate = 9600; 
		USART_InitStructure.USART_WordLength = USART_WordLength_8b; /* 设置字节长度 */ 
		USART_InitStructure.USART_StopBits = USART_StopBits_1; /* 设置停止位 */
		USART_InitStructure.USART_Parity = USART_Parity_No; /* 设置校验位 */ 
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;/* 设置硬件流控制模式使能 */
		USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  /* 设置发送和接收模式 */
		
		USART_Init(USART1, &USART_InitStructure);
	
		/* 打开串口一 */
	  USART_Cmd(USART1,ENABLE);
}




