#include "beepkey.h"

/**************************************************************************
* �� �� ��         : delay
* ��������		   : ������ʱ����
* ��    ��         : ��
* ��    ��         : ��
**************************************************************************/
void delay(u32 i)
{
	while(i--) ;
}

/*************************************************************************
* �� �� ��         : BeepInit
* ��������		   : �������˿ڳ�ʼ������	   ͨ���ı�Ƶ�ʿ��������仯
* ��    ��         : ��
* ��    ��         : ��
**************************************************************************/
void BeepInit()	  //�˿ڳ�ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;	//����һ���ṹ�������������ʼ��GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);   /* ����GPIOʱ�� */

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;		//ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;		  //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	 /* ��ʼ��GPIO */
}

/************************************************************************
* �� �� ��         : KeyInit
* ��������		   : �����˿ڳ�ʼ������	   ͨ���ı�Ƶ�ʿ��������仯
* ��    ��         : ��
* ��    ��         : ��
*************************************************************************/
void KeyInit()
{
	GPIO_InitTypeDef GPIO_InitStructure;	//����һ���ṹ�������������ʼ��GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);   /* ����GPIOʱ�� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //������������ģʽ
	GPIO_Init(GPIOE, &GPIO_InitStructure); 
}


/*************************************************************
* �� �� ��         : sound1
* ��������		   : ��������������
* ��    ��         : ��
* ��    ��         : ��
**************************************************************/
void sound1()  //�Ȼ�������
{
	u32 i=5000;
	while(i--)			   //����һ��ʱ���PWM����ʹ����������
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_8);		 //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOC,GPIO_Pin_8);	  //IO������͵�ƽ
		delay(i--);
	}	
}

/*************************************************************
* �� �� ��         : sound2
* ��������		   : ��������������	  ͨ���ı�Ƶ�ʿ��������仯
* ��    ��         : ��
* ��    ��         : ��
**************************************************************/
void sound2()  //�綯������
{
	u32 i=1000;
	while(i--)					//����һ��ʱ���PWM����ʹ����������
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_8);	   //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOC,GPIO_Pin_8);	//IO������͵�ƽ
		delay(i--);
	}	
}

/************************************************************************
* �� �� ��         : BeepKey
* ��������		   : ��ⰴ��   ���Ʒ���������ͬ������
* ��    ��         : ��
* ��    ��         : ��
*************************************************************************/
void BeepKey()
{
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)==0)	  //�жϰ���PE0�Ƿ���
			{
				delay_ms(10); //��������
				if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)==0)	 //�ٴ��жϰ���PE0�Ƿ���
				{
					sound1()  ;				
				}
				while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)==0); //�ȴ������ɿ�
			}
			
			if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==0)	  //�жϰ���PE1�Ƿ���
			{
				delay_ms(10); //��������
				if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==0)	 //�ٴ��жϰ���PE1�Ƿ���
				{
					sound2();				
				}
				while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==0); //�ȴ������ɿ�
			}
	}
}

