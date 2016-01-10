#include<stm32f10x.h>
#include"TSUsart.h"
#include<stdio.h>


int main(void){
	StandardDebugInit();
	while(1){
		printf("hello\n");
	}
}

