#include<stdio.h>
#include<stm32f10x.h>


#ifndef TSIO_H_
#define TSIO_H_
typedef struct{
	GPIO_TypeDef* GPIOx;
  uint16_t GPIO_Pin;      
  GPIOSpeed_TypeDef GPIO_Speed; 
  GPIOMode_TypeDef GPIO_Mode;    
} TSIOOperationUnit;

typedef struct  {
	TSIOOperationUnit struct_GPIO;//对这个操作的IO口进行描述
	
	//func
	void (*High)(TSIOOperationUnit *struct_GPIO);
	void (*Low)(TSIOOperationUnit *struct_GPIO);
	uint8_t (*ReadBit)(TSIOOperationUnit *struct_GPIO);
} TSIOOperation;

/** 
  * @brief  标准初始化IO的方法  
	* @return 返回一个可以操控这些IO的结构体
  */
extern	void TSStandardIOInit(GPIO_TypeDef* GPIOx,							//Such as:GPIOA
												uint16_t GPIO_Pin,								//Such as:GPIO_Pin_1|GPIO_Pin_2
												GPIOMode_TypeDef GPIO_Mode,				//Such as:GPIO_Mode_Out_OD
												GPIOSpeed_TypeDef GPIO_Speed, 	  //Such as:GPIO_Speed_50MHz
												TSIOOperation *operator_IO);		        //用来返回操作的对象

#endif

