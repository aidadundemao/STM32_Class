#include "led.h"
#include "key.h"
#include "beep.h"
#include "mydelay.h"
void LED_delay(uint8_t delay);
uint8_t add_delay(uint8_t delay);
uint8_t decrease_delay(uint8_t delay);
/*******************************************************************************
 ��������: main
 ����˵��: ������ 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
int main(void)
{
 	uint8_t key=0,delay = 5;	
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
				case WKUP_PRES:DEEP;LED1_OFF;LED2_OFF;            break;                  //LED1 LED2 Ϩ��
				case KEY2_PRES:DEEP;delay = decrease_delay(delay);break;                   //��СLED�������ļ��
				case KEY1_PRES:DEEP;delay = add_delay(delay);     break;                   //����LED�������ļ��	 
				case KEY0_PRES:DEEP;LED_delay(delay);             break;                   //Ĭ��LED���ļ��  
			}
		}
        
        
        
	}	 
}
/*******************************************************************************
 ��������: LED_delay
 ����˵��: ����LED�ļ����� 
 ��    ��: ��
 �� �� ֵ: ��
*******************************************************************************/
void LED_delay(uint8_t delay)
{
  LED1_ON;delay_ms(100 * delay);LED2_ON;
}

/*******************************************************************************
 ��������: LED_delay
 ����˵��: ����LED�ļ�� 
 ��    ��: ��ʱ
 �� �� ֵ: ��ʱ
*******************************************************************************/
uint8_t add_delay(uint8_t delay)
{
  uint8_t i;
  i = delay + 1;
  if(i > 20)   //�����ʱ2s
  {
    i = 20;
  }
  return i;
}

/*******************************************************************************
 ��������: LED_delay
 ����˵��: ����LED�ļ�� 
 ��    ��: ��ʱ
 �� �� ֵ: �������ʱ
*******************************************************************************/
uint8_t decrease_delay(uint8_t delay)
{
  uint8_t i;
  if(delay == 0) //��С0ms
  {
    i  = 0;
  }else
  {
    i = delay - 1;
  }
  return i;
}
