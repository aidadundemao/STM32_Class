
#include "stm32f10x.h"

/*******************************************************************************
 ��������: RCC_Configuration
 ����˵��: ����GPIOB��BPIOE�˿�ʱ�Ӻ��� 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
void RCC_Configuration(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);
}
/*******************************************************************************
 ��������: GPIO_Configuration
 ����˵��: PE5��PE5���ų�ʼ������
 ��    ��: ��
 �� �� ֵ: ��
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


