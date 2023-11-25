#include "gpio.h"
#include "stm32f10x.h"                  // Device header

/**
	*串口端口引脚的配置以及使能端口的时钟
	*PA9   TXD 输出：复用推完输出
	*PA10  RXD 输入：
*/
void GPIO_Configuration(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		/* 打开GPIO口的时钟 */	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		/* 发送引脚的配置 */	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		/* 接收引脚配置 */	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
		//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 输入不用时钟信号
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
}
