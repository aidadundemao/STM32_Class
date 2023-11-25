#include "gpio.h"
#include "stm32f10x.h"                  // Device header

/**
	*���ڶ˿����ŵ������Լ�ʹ�ܶ˿ڵ�ʱ��
	*PA9   TXD ����������������
	*PA10  RXD ���룺
*/
void GPIO_Configuration(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		/* ��GPIO�ڵ�ʱ�� */	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		/* �������ŵ����� */	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		/* ������������ */	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
		//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; ���벻��ʱ���ź�
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);
}
