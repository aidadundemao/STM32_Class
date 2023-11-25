
实验器材:
	战舰STM32F103开发板V3版本
实验目的:
	学习GPIO作为输入的使用	
硬件资源:
	1.DS0(连接在PB5),DS1(连接在PE5)
	2.蜂鸣器(连接在PB8)
	3.按键KEY0(PE4)/KEY1(PE3)/KEY2(PE2)/KEY_UP(PA0,也称之为WK_UP)
实验现象:
	本实验,通过开发板上载有的4个按钮（KEY_UP、KEY0、KEY1和KEY2），来控制板
	上的2个LED（DS0和DS1）和蜂鸣器，其中WK_UP控制蜂鸣器，按一次叫，再按一次
	停；KEY2控制红色的DS0，按一次亮，再按一次灭；KEY1控制绿色的DS1，效果同KEY2；
	KEY0则同时控制DS0和DS1，按一次，他们的状态就翻转一次。
	
GPIO应用步骤：
（1）使能（打开）GPIOx端口时钟。
由函数RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)完成。
（2）GPIOx端口初始化。
选择端口引脚、工作模式、最大翻转速度，由函数GPIO_Init()完成初始化。
（3）I/O口应用编程。	