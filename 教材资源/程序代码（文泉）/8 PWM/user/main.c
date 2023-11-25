/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"
u8 hour,minute,second;
/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
	u8 dir=1;//����
	u32 Duty=0;	  	  
	TIM3_PWMInit();	 //PWM��ʼ��
	while(1)
	{
		delay_ms(10);
		if(dir==1)		
		{
			Duty++;
			if(Duty>300)	dir=0;				
		}
		else
		{
			Duty--;
			if(Duty==0)   dir=1;			
		}
		TIM_SetCompare1(TIM3, Duty);//����TIMx����Ƚ�1�Ĵ���ֵ	
		TIM_SetCompare2(TIM3, Duty);//����TIMx����Ƚ�2�Ĵ���ֵ		
	}
}



