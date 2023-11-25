#include "mydelay.h"

/*******************************************************************************
 函数名称: delay_us
 函数说明: 微秒us延时函数
 输入参数: nus
 返 回 值: 无
*******************************************************************************/
void delay_us(uint16_t nus)
{
    uint16_t i=0;  
    while(nus--)
    {
        i=8;                                  //根据主频调整
        while(i--);    
    }
}
/*******************************************************************************
 函数名称: Delay
 函数说明: 毫秒ms延时函数。此延时模式会空耗CPU大量的时间，仅供入门学习STM32单片机编程时使用
 输入参数: counter 
 返 回 值: 无
*******************************************************************************/
void delay_ms(uint16_t nms)                                      
{
	uint16_t counter=0;
	while(nms--)
	{
	  counter=8000;                              //根据主频调整
		while(counter--);
	}                                  
}
