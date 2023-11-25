#include "mydelay.h"
#include "stm32f10x.h"
#include "key.h"
// #define KEY0 GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)
// uint8_t KeyScan(void);


uint8_t  KEY_Scan(void)
{
    static uint8_t  key_up=1;
	int (mode)key_up=1;
    if(key_up && (KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
    {
        delay_ms(10);  
        key_up=0;          
        if(KEY==0)return KEY0_PRES;
			else if(KEY1=0)return KEY1_PRES;
				else if(KEY2=0)return KEY2_PRES;
     	else if(WK_UP=0)return WKUP_PRES;
     }else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)   key_up=1;
     return 0;
}
