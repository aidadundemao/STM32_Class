/********************************************************************************************
 项目说明：点亮LED0。硬件电路见正点原子电路原理图，LED0、LED1与PB5、PE5引脚的链接关系。
*******************************************************************************************/
#include "stm32f10x.h"
#include "mydelay.h"
#include "led.h"
#include "exit.h"

#define KEY0 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define KEY1 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define KEY2 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)
#define KEY_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
uint8_t flag = 0;
/*******************************************************************************
 函数名称: main
 函数说明: 主函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
int main(void)
{ 
  RCC_Configuration();                             //调用时钟初始化函数
  GPIO_Configuration();//调用GPIO初始化函数，初始化端口GPIOB、GPIOE
  NVIC_Conguration();
  EXTI_Conguration();
  while(1)
  {
		switch(flag)
			{				  
				case 4:	GPIOB->ODR^=0x100;flag =0; break;                  //控制蜂鸣器
				case 3:	GPIOB->ODR^=0x20;flag =0; break;                   //控制LED0翻转
				case 2:	GPIOE->ODR^=0x20;flag =0; break;                   //控制LED1翻转	 
				case 1:	GPIOB->ODR^=0x20; 
				        GPIOE->ODR^=0x20;flag =0; break;                   //同时控制LED0,LED1翻转 
			}
  }
}


void EXTI4_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line4) != RESET )
		{
			delay_ms(20); //按键抖动的处�
			if(KEY0 == 0)
			{
				flag = 1;
			}
		
			
			EXTI_ClearITPendingBit(EXTI_Line4);
		}

}
void EXTI3_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line3) != RESET )
		{
			delay_ms(20); //按键抖动的处�
		
			 if(KEY1 == 0)
			{
				flag = 2;
			}
	
			
			EXTI_ClearITPendingBit(EXTI_Line3);
		}

}
void EXTI2_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line2) != RESET )
		{
			delay_ms(20); //按键抖动的处�
			if(KEY2 == 0)
			{
				flag = 3;
			}
			EXTI_ClearITPendingBit(EXTI_Line2);
		}

}
void EXTI0_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line0) != RESET )
		{
	
			 if(KEY_UP == 1)
			{
				flag = 4;
			}
			
			EXTI_ClearITPendingBit(EXTI_Line0);
		}

}
