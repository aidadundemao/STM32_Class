/****************************************************************
                   Source file of timer.c
****************************************************************/
#include "timer.h"
/****************************************************************
* Function Name  : TIM6Init
* Description    : TIM6 Initialization
* Input          : None
* Output         : None
* Return         : None
****************************************************************/
void TIM6Init()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
	NVIC_InitTypeDef NVIC_InitStructure;
	//��TIM6��APB1ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6 , ENABLE);
	//�����Զ���װ�ؼĴ������ڵ�ֵ �Ĵ�����ֵΪ����ֵ-1
	TIM_TimeBaseStructure.TIM_Period = 36000-1; 
	//����Ԥ��Ƶϵ�� Ԥ��Ƶ�Ĵ�����ֵΪ��Ƶϵ��-1
	TIM_TimeBaseStructure.TIM_Prescaler = 2000-1;
	//����ʱ�ӷָ�:TDTS = Tck_tim	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	//TIM���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	//��ʼ��TIM6��ʱ��
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); 
	//���TIMx���жϴ�����λ:TIMx �ж�Դ
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	/* �����жϲ����������ж� */
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	//ʹ�ܻ���ʧ��TIMx����
	TIM_Cmd(TIM6,ENABLE);	
	/* ����NVIC���� �����ȼ� ���ж�*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn; //ָ���ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//������ռʽ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//������Ӧʽ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //�ж�ʹ��
	NVIC_Init(&NVIC_InitStructure); 	
}




