#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
#include <stdio.h>
void GPIO_USART1_Init(uint32_t BaudRate);	
void NVIC_Configuration(void);
	
#endif
