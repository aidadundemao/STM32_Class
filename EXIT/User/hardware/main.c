/********************************************************************************************
 ��Ŀ˵��������LED0��Ӳ����·������ԭ�ӵ�·ԭ��ͼ��LED0��LED1��PB5��PE5���ŵ����ӹ�ϵ��
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
 ��������: main
 ����˵��: ������ 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
int main(void)
{ 
  RCC_Configuration();                             //����ʱ�ӳ�ʼ������
  GPIO_Configuration();//����GPIO��ʼ����������ʼ���˿�GPIOB��GPIOE
  NVIC_Conguration();
  EXTI_Conguration();
  while(1)
  {
		switch(flag)
			{				  
				case 4:	GPIOB->ODR^=0x100;flag =0; break;                  //���Ʒ�����
				case 3:	GPIOB->ODR^=0x20;flag =0; break;                   //����LED0��ת
				case 2:	GPIOE->ODR^=0x20;flag =0; break;                   //����LED1��ת	 
				case 1:	GPIOB->ODR^=0x20; 
				        GPIOE->ODR^=0x20;flag =0; break;                   //ͬʱ����LED0,LED1��ת 
			}
  }
}


void EXTI4_IRQHandler(void)
{
		if(EXTI_GetITStatus(EXTI_Line4) != RESET )
		{
			delay_ms(20); //���������Ĵ��
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
			delay_ms(20); //���������Ĵ��
		
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
			delay_ms(20); //���������Ĵ��
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
