
#include "usart.h"

uint8_t receiveData[255]={0};
uint8_t receiveFinish=0;
/*******************************************************************************
 ��������: main
 ����˵��: ������ 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
int main(void)
{
   GPIO_USART1_Init(9600);                                                  //����USART1��ʼ������
	 NVIC_Configuration();

	 while(1)
	 {
		 if(receiveFinish==1)
	   {
		   printf("����ܵ����ݣ�%s",receiveData);
		   receiveFinish=0;
	   }
   }		 
}
 
void USART1_IRQHandler (void)
{
  static uint8_t rev_cnt=0;
	uint8_t ch;
	/*----�����ж�----*/
	if(USART_GetITStatus(USART1, USART_IT_RXNE)==SET)
	{
	  ch= USART_ReceiveData(USART1);
	  receiveData[rev_cnt]=ch;
		rev_cnt++;
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
  /*----�����ж�----*/
  else if(USART_GetITStatus(USART1, USART_IT_IDLE)==SET)
	{
	   ch= USART_ReceiveData(USART1);
	   receiveData[rev_cnt]='\0';
		 receiveFinish=1;
	   rev_cnt=0;
		 USART_ClearITPendingBit(USART1, USART_IT_IDLE);
	}
}
