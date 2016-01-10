#include<stm32f10x.h>

#ifndef TSTOOLS_H_
#define TSTOOLS_H_

#define SYSCLK 72000000
#define SysTickCLK (SYSCLK/1000000)



extern void delay_ms(u16 nms);
extern	void delay_us(u16 Nus);
	
#endif
