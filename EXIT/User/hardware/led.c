
#include "stm32f10x.h"

/*******************************************************************************
 ��������: RCC_Configuration
 ����˵��: ����GPIOB��BPIOE�˿�ʱ�Ӻ��� 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
void RCC_Configuration(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}
/*******************************************************************************
 ��������: GPIO_Configuration
 ����˵��: PE5��PE5���ų�ʼ������
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	/*LED����ض˿ں�����*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				               //BEEP-->PB.8 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		           //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	               //�ٶ�Ϊ2MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);	                         //���ݲ�����ʼ��GPIOB.8
	
	/* ����KEY0��������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	
	//
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3;            //KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                               //���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);                                      //��ʼ��GPIOE2,3,4

	//��ʼ�� WK_UP-->GPIOA.0	  ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
	
	
	
}
