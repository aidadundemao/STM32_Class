
#include "usart.h"
/*******************************************************************************
 函数名称: USART1_Configuration
 函数说明: 串口USART1初始化函数 
 输    入: 形参BaudRate(波特率)
 返 回 值: 无
*******************************************************************************/
void GPIO_USART1_Init(uint32_t BaudRate)							                       
{																
  GPIO_InitTypeDef GPIO_InitStructure;			           		   	    //定义GPIO管脚初始化结构体
  USART_InitTypeDef USART_InitStructure;							            //定义串口初始化结构体
	
	/*-----打开GPIO口时钟和串口时钟-----*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);            //使能(打开)GPIOA端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);           //使能USART1的时钟

	/*-----初始化I/O口(用于串行通信引脚)-----*/
  //Configure USART1 Tx (PA.09) as alternate function push-pull
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			                  //选中串口默认管脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	                //定义管脚9的模式：复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		            //定义输出最大速率
  GPIO_Init(GPIOA, &GPIO_InitStructure);			                    //调用函数，对结构体参数进行初始化
  //Configure USART1 Rx (PA.10) as input floating		         
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	                    //选中串口默认管脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;			      //定义管脚10的模式：浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);						              //调用函数，对结构体参数进行初始化

	/*-----串口初始化设置-----*/
  USART_InitStructure.USART_BaudRate = BaudRate;			           	//设置串口通信时波特率
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;		  //设置数据位的长度8个位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;	        //设置1个停止位
  USART_InitStructure.USART_Parity = USART_Parity_No ;	          //设置校验位“无”
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//设置硬件控制流失能
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//设置发送使能、接收使能
  USART_Init(USART1, &USART_InitStructure);	                      //对以上赋完值的结构体进行初始化
    
	/*-----使能串口(打开串口)-----*/
  USART_Cmd(USART1, ENABLE);			                                //开启USART1,注意与上面RCC_APB2PeriphClockCmd()设置的区别
  USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);
  USART_ITConfig(USART1, USART_IT_IDLE,ENABLE);
}

/*******************************************************************************
 函数名称: NVIC_Configuration
 函数说明: 设置嵌套向量中断控制器(中断优先级管理器)NVIC
 输入参数: 无
 返 回 值: 无
*******************************************************************************/
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;                         //定义中断向量结构体变量
	/* 对优先级进行分组 */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);			         //设置NVIC优先级分组为组1：抢先优先级1位，子优先级3位
  /* 配置NVIC */
  NVIC_InitStructure.NVIC_IRQChannel =  USART1_IRQn;		         //选择中断通道或中断源(stm32f10x.h文件中第190行),即设置KEY0键为外部中断输入方式
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级设置为0
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		       //响应优先级设置为1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			         //启动此通道的中断EXTI0
  NVIC_Init(&NVIC_InitStructure);							                 //中断初始化 
}
/*******************************************************************************
 函数名称: fputc
 函数说明: 重定义putc函数，这样可以使用printf函数从串口1打印输出
 输入参数: 无
 返 回 值: 无
*******************************************************************************/
int fputc(int ch,FILE *p)                                         //函数默认的 在使用printf函数时自动调用
{
	USART_SendData(USART1,(uint8_t)ch);	                            //写一个字节到USART
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}
//int fputc(int ch,FILE *f)											                  //重定向fputc函数，同上面的函数是等价的
//{
//	while((USART1->SR & 0x40) == 0);
//	USART1->DR = (u8)ch;
//	return ch;
//}
/*******************************************************************************
 函数名称: fputc
 函数说明: 重定义getc函数，这样可以使用scanff函数从串口1输入数据
 输入参数: 无
 返 回 值: 无
*******************************************************************************/
int fgetc(FILE *f) 
{ 	
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);   //等待串口1输入数据
	return (int)USART_ReceiveData(USART1); 
}
