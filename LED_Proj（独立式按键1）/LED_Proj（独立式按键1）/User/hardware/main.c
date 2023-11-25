/********************************************************************************************
 项目说明：点亮LED0。硬件电路见正点原子电路原理图，LED0、LED1与PB5、PE5引脚的链接关系。
*******************************************************************************************/
#include "stm32f10x.h"
#include "mydelay.h"
#include "led.h"
#include "key.h"
/*******************************************************************************
 函数名称: main
 函数说明: 主函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
int main(void)
{ 
	uint8_t KeyValue=0;
  RCC_Configuration();                             //调用时钟初始化函数
  GPIO_Configuration();	                           //调用GPIO初始化函数，初始化端口GPIOB、GPIOE

  while(1)
  {
		KeyValue=KeyScan();
    if(KeyValue==0xff)
    {			
		  GPIOB->ODR = GPIOB->ODR ^ 0x20;               //GPIO_ResetBits(GPIOB,GPIO_Pin_5);  大口大口
	    GPIOE->ODR = GPIOE->ODR ^ 0x20; 	  
		  GPIOB->ODR = GPIOB->ODR ^ 0x0100;
		}
  }
}

