#include "led.h"
#include "key.h"
#include "beep.h"
/*******************************************************************************
 函数名称: main
 函数说明: 主函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
int main(void)
{
 	uint8_t key=0;	
 	GPIO_LED_Init();			                                           //LED端口初始化
	GPIO_KEY_Init();                                                 //初始化与按键连接的硬件接口
	GPIO_BEEP_Init();                                   	           //初始化蜂鸣器端口

	while(1)
	{
 		key=KEY_Scan(0);	                                             //得到键值
	  if(key)
		{						   
			switch(key)
			{				  
				case WKUP_PRES:	GPIOB->ODR^=0x100; break;                  //控制蜂鸣器
				case KEY2_PRES:	GPIOB->ODR^=0x20; break;                   //控制LED0翻转
				case KEY1_PRES:	GPIOE->ODR^=0x20; break;                   //控制LED1翻转	 
				case KEY0_PRES:	GPIOB->ODR^=0x20; 
				                GPIOE->ODR^=0x20; break;                   //同时控制LED0,LED1翻转 
			}
		}
	}	 
}
 
