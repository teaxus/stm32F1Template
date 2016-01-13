#include "TSLibConfig.h"
#include"TSIO.h"


//更改IO模式
void changeIOMode(TSIOOperationUnit *struct_GPIO,GPIOMode_TypeDef mode){
	GPIO_InitTypeDef GPIO_InitStructure;
	if(struct_GPIO != nil){
		GPIO_InitStructure.GPIO_Mode = mode;
		GPIO_InitStructure.GPIO_Pin = struct_GPIO->GPIO_Pin;
		GPIO_InitStructure.GPIO_Speed = struct_GPIO->GPIO_Speed;
		GPIO_Init(struct_GPIO->GPIOx, &GPIO_InitStructure);  
	}
}
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
	uint8_t result = 0;
	GPIOMode_TypeDef mode_bak;
	
	if (struct_GPIO != nil){
		mode_bak = struct_GPIO->GPIO_Mode;//备份一下当前的模式
		//这个地方可以设定输入的时候的输入模式 我这里选择了 GPIO_Mode_Out_OD
		if (struct_GPIO->GPIO_Mode != GPIO_Mode_Out_OD){
			changeIOMode(struct_GPIO,GPIO_Mode_Out_OD);
		}
		
		result = GPIO_ReadInputDataBit(struct_GPIO->GPIOx,struct_GPIO->GPIO_Pin);
		changeIOMode(struct_GPIO,mode_bak);
	}
	return result;
}


void TSStandardIOInit(GPIO_TypeDef* GPIOx,
											uint16_t GPIO_Pin,
											GPIOMode_TypeDef GPIO_Mode,
											GPIOSpeed_TypeDef GPIO_Speed,
										  TSIOOperation *operator_IO){
	GPIO_InitTypeDef GPIO_InitStructure;
												
	operator_IO->struct_GPIO.GPIOx = GPIOx;
	operator_IO->struct_GPIO.GPIO_Pin = GPIO_Pin;
	operator_IO->struct_GPIO.GPIO_Speed = GPIO_Speed;
  operator_IO->struct_GPIO.GPIO_Mode = GPIO_Mode;
												
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

