
#include "usart.h"

extern uint8_t receiveFinish;
extern uint8_t receiveData[255];
/*******************************************************************************
 ��������: main
 ����˵��: ������ 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
int main(void)
{
  GPIO_USART1_Init(115200);	                                       //��ʼ������USART1
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	                 //�жϷ���2
	
	while(1)
	{
 		if(receiveFinish==1)									                         //���ݽ�����־
		{
			receiveFinish = 0;
			printf("����������������:%s",receiveData);                 //�ѴӴ������ֽ��յ��ַ���ͨ��printf�������ش���������ʾ
		}

	}	 
}
