#include "mydelay.h"
#include "stm32f10x.h"
#include "key.h"
// #define KEY0 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)
// uint8_t KeyScan(void);

uint8_t KeyScan(void)
{
	 uint8_t Flag=0x00;
   if(KEY0==0)
	 {
	    delay_ms(10);
	    if(KEY0==0)
	    {
			   while(KEY0==0)
				   ;
				 Flag = ~Flag;
			}	 
	 }
	 return Flag;
}
