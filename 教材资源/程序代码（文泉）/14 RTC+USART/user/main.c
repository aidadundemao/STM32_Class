/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"
u8 hour,minute,second;
u8 smgduan[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u16 smgwei[6]={0x7fff,0xbfff,0xdfff,0xefff,0xf7ff,0xfbff};

//�˴�Ҫע��һά�±�Ϊ������ά�±�Ϊͨ���� ��Ϊ�ɼ��Ƿִν��е�
u16 AD_Value[20][4]; //ADת�����4��ͨ��ÿ��ͨ��20��
u16 After_filter[4]; //�˲������ֵ ��4��ͨ��

/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
	printf_init();
	EXTIInti();
	DsgShowInit();
	clockinit_RTC();  //ʱ���ʼ��	
	while(1)
	{
		DsgShowTime();
	}	
			
}


