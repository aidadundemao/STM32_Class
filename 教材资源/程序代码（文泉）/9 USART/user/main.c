/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"

//define three extern variable
u8 hour,minute,second;

/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
	hour=9;	minute=30;second=25;
	DsgShowInit();//����ܹܽų�ʼ��
	EXTIInti();//�ⲿ�жϳ�ʼ��
	TIM6Init();//��ʱ����ʼ��
	Usart1_Init();//���ڳ�ʼ��
	while(1)
	{
		DsgShowTime();//��̬ɨ����ʾʱ��
	}		
}



