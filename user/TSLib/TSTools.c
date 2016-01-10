#include<stdio.h>
#include"TSLibConfig.h"
#include"TSTools.h"
#include<stm32f10x.h>

const u8 fac_us = SysTickCLK/20;
const u16 fac_ms = (SysTickCLK/8)*1000;
//dalay Nms
//PS:just ms level
//in 72M,Nms<=1864
void delay_ms(u16 nms){
	u32 temp;
	SysTick->CTRL = 0xfffffffb;
	SysTick->LOAD = (u32)nms*fac_ms;
	SysTick->VAL = 0x00;//clear
	SysTick->CTRL = 0x01;//begin count
	do{
		temp = SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//wait time up
	SysTick->CTRL = 0x00;//close timer
	SysTick->VAL = 0x00;//clear count
}

//dalay Nus
//PS:just us level
//in 72M,Nus<=1864
void delay_us(u16 Nus){
	u32 temp;
	SysTick->CTRL = 0xfffffffb;
	SysTick->LOAD = (u32)Nus*fac_us;
	SysTick->VAL = 0x00;//clear
	SysTick->CTRL = 0x01;//begin count
	do{
		temp = SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//wait time up
	SysTick->CTRL = 0x00;//close timer
	SysTick->VAL = 0x00;//clear count
}
