#include<stm32f10x.h>

void StandardInitUsart1(void){
	USART_InitTypeDef     USART_InitStructure;
	USART_InitStructure.USART_BaudRate= 115200;     
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; 
	USART_InitStructure.USART_StopBits = USART_StopBits_1;      
	USART_InitStructure.USART_Parity= USART_Parity_No ;         
	USART_InitStructure.USART_HardwareFlowControl= USART_HardwareFlowControl_None; //
	USART_InitStructure.USART_Mode =USART_Mode_Rx |USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE);
}
