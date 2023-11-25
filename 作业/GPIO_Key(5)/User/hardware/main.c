#include "led.h"
#include "key.h"
#include "beep.h"
#include "mydelay.h"
void LED_delay(uint8_t delay);
uint8_t add_delay(uint8_t delay);
uint8_t decrease_delay(uint8_t delay);
/*******************************************************************************
 函数名称: main
 函数说明: 主函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
int main(void)
{
 	uint8_t key=0,delay = 5;	
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
				case WKUP_PRES:DEEP;LED1_OFF;LED2_OFF;            break;                  //LED1 LED2 熄灭
				case KEY2_PRES:DEEP;delay = decrease_delay(delay);break;                   //减小LED依次亮的间隔
				case KEY1_PRES:DEEP;delay = add_delay(delay);     break;                   //增加LED依次亮的间隔	 
				case KEY0_PRES:DEEP;LED_delay(delay);             break;                   //默认LED亮的间隔  
			}
		}
        
        
        
	}	 
}
/*******************************************************************************
 函数名称: LED_delay
 函数说明: 设置LED的间隔多久 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
void LED_delay(uint8_t delay)
{
  LED1_ON;delay_ms(100 * delay);LED2_ON;
}

/*******************************************************************************
 函数名称: LED_delay
 函数说明: 增加LED的间隔 
 输    入: 延时
 返 回 值: 延时
*******************************************************************************/
uint8_t add_delay(uint8_t delay)
{
  uint8_t i;
  i = delay + 1;
  if(i > 20)   //最大延时2s
  {
    i = 20;
  }
  return i;
}

/*******************************************************************************
 函数名称: LED_delay
 函数说明: 减少LED的间隔 
 输    入: 延时
 返 回 值: 处理的延时
*******************************************************************************/
uint8_t decrease_delay(uint8_t delay)
{
  uint8_t i;
  if(delay == 0) //最小0ms
  {
    i  = 0;
  }else
  {
    i = delay - 1;
  }
  return i;
}
