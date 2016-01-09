#include<stm32f10x.h>
//#include"TSUsart.h"
#include<stdio.h>


void GPIO_Configuration(void)
{
GPIO_InitTypeDef  GPIO_InitStructure;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//??UASRT???
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//??GPIOA???,?????,??????,????,???????????
RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
GPIO_InitStructure.GPIO_Pin =GPIO_Pin_9;
GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz; //?????,IO???????
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //??????;??????????GPIO_Mode_Out_PP????????,??????,?????????;
GPIO_Init(GPIOA,&GPIO_InitStructure);
 
GPIO_InitStructure.GPIO_Pin =GPIO_Pin_10;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //???????,????????????IO?????
GPIO_Init(GPIOA,&GPIO_InitStructure);
}
void USART1_config(void)
{
USART_InitTypeDef     USART_InitStructure;
USART_InitStructure.USART_BaudRate= 115200;     //?????
USART_InitStructure.USART_WordLength = USART_WordLength_8b; //?????
USART_InitStructure.USART_StopBits = USART_StopBits_1;      //???
USART_InitStructure.USART_Parity= USART_Parity_No ;         //?????
 
USART_InitStructure.USART_HardwareFlowControl= USART_HardwareFlowControl_None; //???
 
USART_InitStructure.USART_Mode =USART_Mode_Rx |USART_Mode_Tx;
USART_Init(USART1, &USART_InitStructure);
 
USART_Cmd(USART1, ENABLE);
}
void usart_debug_config(void)  //???main???????????
{
GPIO_Configuration(); //IO???
USART1_config();   //????
}
int main(void)
{
// GPIO_InitTypeDef GPIOB_InitStruct;
// GPIO_InitTypeDef GPIOA_InitStruct;
// GPIO_InitTypeDef GPIOC_InitStruct;
// u8 i=0;

// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA,ENABLE);

// GPIOB_InitStruct.GPIO_Pin=GPIO_Pin_0;
// GPIOB_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
// GPIOB_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

// GPIO_Init(GPIOB,&GPIOB_InitStruct);

// GPIOA_InitStruct.GPIO_Pin=GPIO_Pin_0;
// GPIOA_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
// GPIOA_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

// GPIO_Init(GPIOA,&GPIOA_InitStruct);
//	
//	
// GPIOC_InitStruct.GPIO_Pin=GPIO_Pin_5;
// GPIOC_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
// GPIOC_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;

// GPIO_Init(GPIOA,&GPIOA_InitStruct);

 //StandardInitUsart1();
 
 
unsigned char TxBuf1[100] ={"hello!!!\r\n"};
 int  i;
SystemInit();
usart_debug_config();
for( i = 0; TxBuf1[i] != '\0'; i++)
{
while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);//?????fputc?????
USART_SendData(USART1 , TxBuf1[i]);//????????????
while(USART_GetFlagStatus(USART1, USART_FLAG_TC)==RESET);
}
 while(1)
 {
//  i=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1);
//  if(i)
//  {
//    GPIO_ResetBits(GPIOC,GPIO_Pin_0);
//    GPIO_SetBits(GPIOC,GPIO_Pin_0);	
//		
//  }
	
//      while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
//      {}
 }
 
 
 
}
