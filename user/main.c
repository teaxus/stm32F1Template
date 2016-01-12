#include<stm32f10x.h>
#include"TSUsart.h"
#include"TSTools.h"
#include"TSIO.h"
#include<stdio.h>



int main(void){
	float step = -0.01;
	float dd = 0;
	int a=0;
	int b=0;
	
	TSIOOperation operator_IO;
	TSStandardIOInit(GPIOA,GPIO_Pin_1,GPIO_Mode_Out_OD,GPIO_Speed_2MHz,&operator_IO);
	
	SystemInit();
	StandardDebugInit();
	
	while(1){
		//i++;
		if (dd>=0.99){
			step = -0.001;
		}
		if (dd<=0.001){
			step = 0.001;
		}
		dd+=step;
		a = 1000*(1-dd);
		b = 1000*dd;
		if (a==0||b==0){
			continue;
		}
		
		operator_IO.High(&operator_IO.struct_GPIO);
		delay_us(1000*(1-dd));
		operator_IO.Low(&operator_IO.struct_GPIO);
		delay_us(1000*dd);
		
//		GPIO_SetBits(GPIOA,GPIO_Pin_1);
//		delay_ms(1000);
//		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
//		delay_ms(1000);
	}
}
