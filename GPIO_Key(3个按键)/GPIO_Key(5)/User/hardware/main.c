#include "led.h"
#include "key.h"
#include "beep.h"
/*******************************************************************************
 ��������: main
 ����˵��: ������ 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
int main(void)
{
 	uint8_t key=0;	
 	GPIO_LED_Init();			                                           //LED�˿ڳ�ʼ��
	GPIO_KEY_Init();                                                 //��ʼ���밴�����ӵ�Ӳ���ӿ�
	GPIO_BEEP_Init();                                   	           //��ʼ���������˿�

	while(1)
	{
 		key=KEY_Scan(0);	                                             //�õ���ֵ
	  if(key)
		{						   
			switch(key)
			{				  
				case WKUP_PRES:	GPIOB->ODR^=0x100; break;                  //���Ʒ�����
				case KEY2_PRES:	GPIOB->ODR^=0x20; break;                   //����LED0��ת
				case KEY1_PRES:	GPIOE->ODR^=0x20; break;                   //����LED1��ת	 
				case KEY0_PRES:	GPIOB->ODR^=0x20; 
				                GPIOE->ODR^=0x20; break;                   //ͬʱ����LED0,LED1��ת 
			}
		}
	}	 
}
 
