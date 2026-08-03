#include "uart_driver.h"
#include "gpio_driver.h"
#include "rcc_driver.h"

void UART_Init(UART_Handle_t*huart){
	 /* Enable UART Peripheral Clock */
	if(huart->Instance==USART2){
	RCC->APB1ENR |=(1<<17);
	/* Configure GPIO Pins */

	GPIO_AFInit(GPIOA,GPIO_PIN_2,7);
	GPIO_AFInit(GPIOA,GPIO_PIN_3,7);
	}

	    /* Configure Baud Rate */
	uint32_t pclk;
	uint32_t usartdiv;
	pclk=RCC_GetPCLK1Freq();


	usartdiv = (pclk + (huart->Init.Baudrate/2)) / huart->Init.Baudrate;

	huart->Instance->BRR = usartdiv;
//	float divider;
//	uint32_t mantissa;
//	uint32_t fraction;
//
//	pclk=RCC_GetPCLK1Freq();
//	divider=(float)pclk/huart->Init.Baudrate;
//	mantissa=(uint32_t)divider;
//	fraction=(uint32_t)((divider-mantissa)*16+0.5f);
//
//	huart->Instance->BRR=((mantissa<<4)|fraction);
	/* Configure Word Length */

	if(huart->Init.Wordlength==UART_WORDLENGTH_8B){
		huart->Instance->CR1 &= ~(1<<12);
	}
	else if(huart->Init.Wordlength==UART_WORDLENGTH_9B){
		huart->Instance->CR1 |= (1<<12);
	}
	/* Configure Parity */

	if(huart->Init.Parity==UART_PARITY_NONE){
		huart->Instance->CR1 &= ~(1<<10);
	}
	else if(huart->Init.Parity==UART_PARITY_EVEN){
		huart->Instance->CR1 &= ~(3<<9);
		huart->Instance->CR1 |=(1<<10);
	}
	else if(huart->Init.Parity==UART_PARITY_ODD){
		huart->Instance->CR1 &= ~(3<<9);
		huart->Instance->CR1 |= (3<<9);
	}
	/* Configure Stop Bits */

	if(huart->Init.Stopbits==UART_STOPBITS_1){
		huart->Instance->CR2 &= ~(3<<12);
	}
	else if(huart->Init.Stopbits==UART_STOPBITS_2){
		huart->Instance->CR2 &= ~(3<<12);
		huart->Instance->CR2 |= (1<<13);
	}
	/* Enable Transmitter */
	huart->Instance->CR1 &= ~((1<<3) | (1<<2));
	if(huart->Init.Mode==UART_MODE_TX_ONLY){
		huart->Instance->CR1 |=(1<<3);
	}
	/* Enable Receiver */
	else if(huart->Init.Mode==UART_MODE_RX_ONLY){
		huart->Instance->CR1 |=(1<<2);
	}
	else if(huart->Init.Mode==UART_MODE_TX_RX){
		huart->Instance->CR1 |=(1<<3);
		huart->Instance->CR1 |=(1<<2);
	}
	/* Enable UART */
	huart->Instance->CR1 |=(1<<13);

}

void UART_SendChar(UART_Handle_t*huart,char ch){
	while(!(huart->Instance->SR & (1<<7))){
//		Wait until txe becomes 1

	}
	huart->Instance->DR=(uint8_t)ch;

	 while(!(huart->Instance->SR & (1<<6)));

}

void UART_SendString(UART_Handle_t*huart,const char*str){

	while(*str!='\0'){
		UART_SendChar(huart,*str);
		str++;
	}

}

char UART_ReceiveChar(UART_Handle_t*huart){
	while(!(huart->Instance->SR & (1<<5))){
//		Wait Until RXE becomes 0

	}

	char data=(char)(huart->Instance->DR);
	return data;

}



