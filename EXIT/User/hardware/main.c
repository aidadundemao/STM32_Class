/********************************************************************************************
 ÏîÄ¿ËµÃ÷£ºµãÁÁLED0¡£Ó²¼þµçÂ·¼ûÕýµãÔ­×ÓµçÂ·Ô­ÀíÍ¼£¬LED0¡¢LED1ÓëPB5¡¢PE5Òý½ÅµÄÁ´½Ó¹ØÏµ¡£
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
 º¯ÊýÃû³Æ: main
 º¯ÊýËµÃ÷: Ö÷º¯Êý 
 Êä    Èë: ÎÞ
 ·µ »Ø Öµ: ÎÞ
*******************************************************************************/
int main(void)
{ 
  RCC_Configuration();                             //µ÷ÓÃÊ±ÖÓ³õÊ¼»¯º¯Êý
  GPIO_Configuration();//µ÷ÓÃGPIO³õÊ¼»¯º¯Êý£¬³õÊ¼»¯¶Ë¿ÚGPIOB¡¢GPIOE
  NVIC_Conguration();
  EXTI_Conguration();
  while(1)
  {
		switch(flag)
			{				  
				case 4:	GPIOB->ODR^=0x100;flag =0; break;                  //¿ØÖÆ·äÃùÆ÷
				case 3:	GPIOB->ODR^=0x20;flag =0; break;                   //¿ØÖÆLED0·­×ª
				case 2:	GPIOE->ODR^=0x20;flag =0; break;                   //¿ØÖÆLED1·­×ª	 
				case 1:	GPIOB->ODR^=0x20; 
				        GPIOE->ODR^=0x20;flag =0; break;                   //Í¬Ê±¿ØÖÆLED0,LED1·­×ª 
			}
  }
}


void EXTI4_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line4) != RESET )
		{
			delay_ms(20); //°´¼ü¶¶¶¯µÄ´¦À
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
			delay_ms(20); //°´¼ü¶¶¶¯µÄ´¦À
		
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
			delay_ms(20); //°´¼ü¶¶¶¯µÄ´¦À
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
