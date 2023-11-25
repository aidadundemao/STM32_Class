
#include "usart.h"
/*******************************************************************************
 ��������: USART1_Configuration
 ����˵��: ����USART1��ʼ������ 
 ��    ��: �β�BaudRate(������)
 �� �� ֵ: ��
*******************************************************************************/
void GPIO_USART1_Init(uint32_t BaudRate)							                       
{																
  GPIO_InitTypeDef GPIO_InitStructure;			           		   	    //����GPIO�ܽų�ʼ���ṹ��
  USART_InitTypeDef USART_InitStructure;							            //���崮�ڳ�ʼ���ṹ��
	
	/*-----��GPIO��ʱ�Ӻʹ���ʱ��-----*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);            //ʹ��(��)GPIOA�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);           //ʹ��USART1��ʱ��

	/*-----��ʼ��I/O��(���ڴ���ͨ������)-----*/
  //Configure USART1 Tx (PA.09) as alternate function push-pull
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			                  //ѡ�д���Ĭ�Ϲܽ�
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	                //����ܽ�9��ģʽ�������������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		            //��������������
  GPIO_Init(GPIOA, &GPIO_InitStructure);			                    //���ú������Խṹ��������г�ʼ��
  //Configure USART1 Rx (PA.10) as input floating		         
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	                    //ѡ�д���Ĭ�Ϲܽ�
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;			      //����ܽ�10��ģʽ����������
  GPIO_Init(GPIOA, &GPIO_InitStructure);						              //���ú������Խṹ��������г�ʼ��

	/*-----���ڳ�ʼ������-----*/
  USART_InitStructure.USART_BaudRate = BaudRate;			           	//���ô���ͨ��ʱ������
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;		  //��������λ�ĳ���8��λ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;	        //����1��ֹͣλ
  USART_InitStructure.USART_Parity = USART_Parity_No ;	          //����У��λ���ޡ�
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//����Ӳ��������ʧ��
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//���÷���ʹ�ܡ�����ʹ��
  USART_Init(USART1, &USART_InitStructure);	                      //�����ϸ���ֵ�Ľṹ����г�ʼ��
    
	/*-----ʹ�ܴ���(�򿪴���)-----*/
  USART_Cmd(USART1, ENABLE);			                                //����USART1,ע��������RCC_APB2PeriphClockCmd()���õ�����
  USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);
  USART_ITConfig(USART1, USART_IT_IDLE,ENABLE);
}

/*******************************************************************************
 ��������: NVIC_Configuration
 ����˵��: ����Ƕ�������жϿ�����(�ж����ȼ�������)NVIC
 �������: ��
 �� �� ֵ: ��
*******************************************************************************/
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;                         //�����ж������ṹ�����
	/* �����ȼ����з��� */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);			         //����NVIC���ȼ�����Ϊ��1���������ȼ�1λ�������ȼ�3λ
  /* ����NVIC */
  NVIC_InitStructure.NVIC_IRQChannel =  USART1_IRQn;		         //ѡ���ж�ͨ�����ж�Դ(stm32f10x.h�ļ��е�190��),������KEY0��Ϊ�ⲿ�ж����뷽ʽ
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�����Ϊ0
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		       //��Ӧ���ȼ�����Ϊ1
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			         //������ͨ�����ж�EXTI0
  NVIC_Init(&NVIC_InitStructure);							                 //�жϳ�ʼ�� 
}
/*******************************************************************************
 ��������: fputc
 ����˵��: �ض���putc��������������ʹ��printf�����Ӵ���1��ӡ���
 �������: ��
 �� �� ֵ: ��
*******************************************************************************/
int fputc(int ch,FILE *p)                                         //����Ĭ�ϵ� ��ʹ��printf����ʱ�Զ�����
{
	USART_SendData(USART1,(uint8_t)ch);	                            //дһ���ֽڵ�USART
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}
//int fputc(int ch,FILE *f)											                  //�ض���fputc������ͬ����ĺ����ǵȼ۵�
//{
//	while((USART1->SR & 0x40) == 0);
//	USART1->DR = (u8)ch;
//	return ch;
//}
/*******************************************************************************
 ��������: fputc
 ����˵��: �ض���getc��������������ʹ��scanff�����Ӵ���1��������
 �������: ��
 �� �� ֵ: ��
*******************************************************************************/
int fgetc(FILE *f) 
{ 	
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);   //�ȴ�����1��������
	return (int)USART_ReceiveData(USART1); 
}
