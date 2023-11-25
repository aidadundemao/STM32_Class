
#include "usart.h"

uint8_t receiveData[255]={0};
uint8_t receiveFinish=0;
/*******************************************************************************
 函数名称: main
 函数说明: 主函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
int main(void)
{
   GPIO_USART1_Init(9600);                                                  //调用USART1初始化函数
	 NVIC_Configuration();

	 while(1)
	 {
		 if(receiveFinish==1)
	   {
		   printf("你接受的内容：%s",receiveData);
		   receiveFinish=0;
	   }
   }		 
}
 
void USART1_IRQHandler (void)
{
  static uint8_t rev_cnt=0;
	uint8_t ch;
	/*----接受中断----*/
	if(USART_GetITStatus(USART1, USART_IT_RXNE)==SET)
	{
	  ch= USART_ReceiveData(USART1);
	  receiveData[rev_cnt]=ch;
		rev_cnt++;
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
  /*----空闲中断----*/
  else if(USART_GetITStatus(USART1, USART_IT_IDLE)==SET)
	{
	   ch= USART_ReceiveData(USART1);
	   receiveData[rev_cnt]='\0';
		 receiveFinish=1;
	   rev_cnt=0;
		 USART_ClearITPendingBit(USART1, USART_IT_IDLE);
	}
}
