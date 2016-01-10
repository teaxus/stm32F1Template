#include<stm32f10x.h>
#include"TSUsart.h"
#include"TSTools.h"
#include<stdio.h>




int main(void){
	int i=0;
	SystemInit();
	StandardDebugInit();
	//delay_init(72);
	while(1){
		delay_ms(1);
		//i++;
	}
}
