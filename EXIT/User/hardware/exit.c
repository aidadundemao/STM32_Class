#include "exit.h"
#include "stm32f10x.h"                  // Device header


void NVIC_Conguration(void)
{

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd= ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd= ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStructure);
	

	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd= ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd= ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
}




void EXTI_Conguration(void)
{            
	
	EXTI_InitTypeDef EXTI_InitStructure;
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4); //gpio的映射关系，io口和中断线映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3); //gpio的映射关系，io口和中断线映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2); //gpio的映射关系，io口和中断线映射
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); //gpio的映射关系，io口和中断线映射

	
	EXTI_InitStructure.EXTI_Line= EXTI_Line4;
	EXTI_InitStructure.EXTI_LineCmd= ENABLE;	
	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_InitStructure.EXTI_Line= EXTI_Line3;
	EXTI_InitStructure.EXTI_LineCmd= ENABLE;	
	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_InitStructure.EXTI_Line= EXTI_Line2;
	EXTI_InitStructure.EXTI_LineCmd= ENABLE;	
	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	EXTI_InitStructure.EXTI_Line= EXTI_Line0;
	EXTI_InitStructure.EXTI_LineCmd= ENABLE;	
	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger= EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);
}
