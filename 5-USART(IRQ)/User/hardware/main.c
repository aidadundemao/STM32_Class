
#include "usart.h"

extern uint8_t receiveFinish;
extern uint8_t receiveData[255];
/*******************************************************************************
 函数名称: main
 函数说明: 主函数 
 输    入: 无
 返 回 值: 无
*******************************************************************************/
int main(void)
{
  GPIO_USART1_Init(115200);	                                       //初始化串口USART1
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	                 //中断分组2
	
	while(1)
	{
 		if(receiveFinish==1)									                         //数据结束标志
		{
			receiveFinish = 0;
			printf("这是你所发的数据:%s",receiveData);                 //把从串口助手接收到字符串通过printf函数发回串口助手显示
		}

	}	 
}
