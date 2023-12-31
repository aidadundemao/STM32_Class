/****************************************************************
                   Source file of dsgshow.c
****************************************************************/
#include "dsgshow.h"
//declare three extern variable
extern u8 hour,minute,second;
extern u8 smgduan[11];
extern u16 smgwei[6];

/****************************************************************
* 函 数 名         : DsgShowInit
* 函数功能		   : 数码管显示初始化
* 输    入         : 无
* 输    出         : 无
****************************************************************/
void DsgShowInit()
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	//打开GPIOE和GPIOG时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOG , ENABLE); 
	//配置GPIOE为输出推挽模式, 为避免后续中断产生误动作, 只初始化高8位	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_14|GPIO_Pin_13|
	GPIO_Pin_12|GPIO_Pin_11|GPIO_Pin_10|GPIO_Pin_9|GPIO_Pin_8; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ; 
	GPIO_Init(GPIOE, &GPIO_InitStructure); 
	//配置GPIOG为输出推挽模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ; 
	GPIO_Init(GPIOG, &GPIO_InitStructure); 
}

/****************************************************************
* 函 数 名         : DsgShowNum
* 函数功能		   : 数码管显示六位学号
* 输    入         : 无
* 输    出         : 无
****************************************************************/
void DsgShowNum()
{
	u16 i;
	while(1)
	{
		GPIO_Write(GPIOE,0x7FFF);//选中第一个数码管
		GPIO_Write(GPIOG,0xc0); //送第一数字的段码
		for(i=0;i<400;i++)  ;//延时比较短的时间
		GPIO_Write(GPIOE,0xBFFF);
		GPIO_Write(GPIOG,0xf9); 
		for(i=0;i<400;i++)  ;
		GPIO_Write(GPIOE,0xDFFF);
		GPIO_Write(GPIOG,0xa4); 
		for(i=0;i<400;i++)  ;
		GPIO_Write(GPIOE,0xEFFF);
		GPIO_Write(GPIOG,0xb0); 
		for(i=0;i<400;i++)  ;
		GPIO_Write(GPIOE,0xF7FF);
		GPIO_Write(GPIOG,0x99);		
		for(i=0;i<400;i++)  ;
		GPIO_Write(GPIOE,0xFBFF);
		GPIO_Write(GPIOG,0x92);		
		for(i=0;i<400;i++)  ;
	}
}

/****************************************************************
* 函 数 名         : DsgShowNum
* 函数功能		   : 数码管显示时间
* 输    入         : 无
* 输    出         : 无
****************************************************************/
void DsgShowTime()
{
		u16 j;
	
		GPIO_Write(GPIOE,smgwei[0]);	
		GPIO_Write(GPIOG,smgduan[hour/10]);
		for(j=0;j<400;j++);
		GPIO_Write(GPIOE,smgwei[1]);	
		GPIO_Write(GPIOG,(smgduan[hour%10])&0xff7f);
		for(j=0;j<400;j++);
		
		GPIO_Write(GPIOE,smgwei[2]);	
		GPIO_Write(GPIOG,smgduan[minute/10]);
		for(j=0;j<400;j++);
		GPIO_Write(GPIOE,smgwei[3]);	
		GPIO_Write(GPIOG,(smgduan[minute%10])&0xff7f);
		for(j=0;j<400;j++);
		
		GPIO_Write(GPIOE,smgwei[4]);	
		GPIO_Write(GPIOG,smgduan[second/10]);
		for(j=0;j<400;j++);
		GPIO_Write(GPIOE,smgwei[5]);	
		GPIO_Write(GPIOG,smgduan[second%10]);
		for(j=0;j<400;j++);

}
