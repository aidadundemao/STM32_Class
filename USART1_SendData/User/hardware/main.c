/********************************************************************************************
 项目名称：工程模板
*******************************************************************************************/
#include "stm32f10x.h"                  // Device header
#include "usart.h"
#include "gpio.h"
#include "mydelay.h"

int main(void)
{
		GPIO_Configuration();
		USART_Configuartion();
		

		while(1)
		{
			USART_SendData(USART1,'A');
			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) !=SET);
			delay_ms(100);
		}
		
		
}

