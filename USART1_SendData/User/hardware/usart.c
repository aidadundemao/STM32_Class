#include "usart.h"
#include "stm32f10x.h"                  // Device header

void USART_Configuartion(void)
{
		
		USART_InitTypeDef USART_InitStructure;
	
		/* �򿪴��ڵ�ʱ�� */
		// ���ô򿪸���ʱ�ӣ�ֻ����ӳ����ⲿ�ж���Ҫ����ʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
		
	  /* ����ģʽ������ */
		USART_InitStructure.USART_BaudRate = 9600; 
		USART_InitStructure.USART_WordLength = USART_WordLength_8b; /* �����ֽڳ��� */ 
		USART_InitStructure.USART_StopBits = USART_StopBits_1; /* ����ֹͣλ */
		USART_InitStructure.USART_Parity = USART_Parity_No; /* ����У��λ */ 
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;/* ����Ӳ��������ģʽʹ�� */
		USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;  /* ���÷��ͺͽ���ģʽ */
		
		USART_Init(USART1, &USART_InitStructure);
	
		/* �򿪴���һ */
	  USART_Cmd(USART1,ENABLE);
}




