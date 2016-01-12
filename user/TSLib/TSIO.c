#include "TSLibConfig.h"
#include"TSIO.h"

//设置高电平
void setHigh(TSIOOperationUnit *struct_GPIO){
		GPIO_SetBits(struct_GPIO->GPIOx,struct_GPIO->GPIO_Pin);
}
//设置低电平
void setLow(TSIOOperationUnit *struct_GPIO){
		GPIO_ResetBits(struct_GPIO->GPIOx,struct_GPIO->GPIO_Pin);
}
//读取某一个端口的电平
uint8_t ReadBit(TSIOOperationUnit *struct_GPIO){
	return 0;
}

void TSStandardIOInit(GPIO_TypeDef* GPIOx,
											uint16_t GPIO_Pin,
											GPIOMode_TypeDef GPIO_Mode,
											GPIOSpeed_TypeDef GPIO_Speed,
										  TSIOOperation *operator_IO){
	GPIO_InitTypeDef GPIO_InitStructure;
//	TSIOOperationUnit struct_GPIO;	
												
	operator_IO->struct_GPIO.GPIOx = GPIOx;
	operator_IO->struct_GPIO.GPIO_Pin = GPIO_Pin;
	operator_IO->struct_GPIO.GPIO_Speed = GPIO_Speed;
  operator_IO->struct_GPIO.GPIO_Mode = GPIO_Mode;
												
	//operator_IO->struct_GPIO = struct_GPIO;
  operator_IO->High = setHigh;				
  operator_IO->Low = setLow;
	operator_IO->ReadBit = ReadBit;
												
	if (GPIOx == GPIOA){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	}
	else if (GPIOx == GPIOB){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	}
	else if (GPIOx == GPIOC){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	}
	else if (GPIOx == GPIOD){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	}
	else if (GPIOx == GPIOE){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	}
	else if (GPIOx == GPIOF){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	}
	else if (GPIOx == GPIOG){
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);
	}
	else{
		return;
	}

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed;
  GPIO_Init(GPIOx, &GPIO_InitStructure);  
	
	return;
}

