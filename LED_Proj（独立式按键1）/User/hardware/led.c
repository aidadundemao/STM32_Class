
#include "stm32f10x.h"

/*******************************************************************************
 函数名称: RCC_Configuration
 函数说明: 开启GPIOB、BPIOE端口时钟函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
void RCC_Configuration(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);
}
/*******************************************************************************
 函数名称: GPIO_Configuration
 函数说明: PE5、PE5引脚初始化函数
 输    入: 无
 返 回 值: 无
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
		
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
 //GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
 // GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 // GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIOB->ODR = 0xff;
	  GPIOE->ODR = 0xff;
}


