#include<stm32f10x.h>

void StandardInitUsart1(void){
  USART_InitTypeDef USART_InitStructure;//
	USART_ClockInitTypeDef USART_ClockInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	 /* PA9 USART1_Tx */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //(TX)
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* PA10 USART1_Rx  */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//(RX)
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	
//	USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;     
//  USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;      
//  USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;      
//  USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable; 
//  USART_ClockInit(USART1, &USART_ClockInitStructure);
	
	
  USART_InitStructure.USART_BaudRate = 115200;// 
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;// 
  USART_InitStructure.USART_StopBits = USART_StopBits_1;//
  USART_InitStructure.USART_Parity = USART_Parity_No;//
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//
  USART_InitStructure.USART_Mode = USART_Mode_Tx;//|USART_Mode_Rx;//
//  USART_InitStructure.USART_Clock = USART_Clock_Disable;//
//  USART_InitStructure.USART_CPOL = USART_CPOL_Low;//
//  USART_InitStructure.USART_CPHA = USART_CPHA_2Edge;//
//  USART_InitStructure.USART_LastBit = USART_LastBit_Disable;//
  /* Configure USART1 */ 
  USART_Init(USART1, &USART_InitStructure);//

  /* Enable the USART1 */ 
  USART_Cmd(USART1, ENABLE);//
	
	



//GPIO_InitTypeDef GPIO_InitStructure;
//USART_InitTypeDef USART_InitStructure;
// 
//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
//RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//GPIO_Init(GPIOB, &GPIO_InitStructure);
// 
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//GPIO_Init(GPIOB, &GPIO_InitStructure);
// 
//USART_InitStructure.USART_BaudRate = 115200;
//USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//USART_InitStructure.USART_StopBits = USART_StopBits_1;
//USART_InitStructure.USART_Parity = USART_Parity_No;
//USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//USART_Init(USART3, &USART_InitStructure);
// 
//USART_Cmd(USART3, ENABLE);
}
