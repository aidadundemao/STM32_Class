#include "mydelay.h"

/*******************************************************************************
 ��������: delay_us
 ����˵��: ΢��us��ʱ����
 �������: nus
 �� �� ֵ: ��
*******************************************************************************/
void delay_us(uint16_t nus)
{
    uint16_t i=0;  
    while(nus--)
    {
        i=8;                                  //������Ƶ����
        while(i--);    
    }
}
/*******************************************************************************
 ��������: Delay
 ����˵��: ����ms��ʱ����������ʱģʽ��պ�CPU������ʱ�䣬��������ѧϰSTM32��Ƭ�����ʱʹ��
 �������: counter 
 �� �� ֵ: ��
*******************************************************************************/
void delay_ms(uint16_t nms)                                      
{
	uint16_t counter=0;
	while(nms--)
	{
	  counter=8000;                              //������Ƶ����
		while(counter--);
	}                                  
}