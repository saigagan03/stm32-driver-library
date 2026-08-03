/*
 * uart_driver.h
 *
 *  Created on: 02-Aug-2026
 *      Author: Lenovo
 */

#ifndef INC_UART_DRIVER_H_
#define INC_UART_DRIVER_H_
#include<stdint.h>
#include "stm32f446xx.h"

#define UART_MODE_TX_ONLY 0
#define UART_MODE_RX_ONLY 1
#define UART_MODE_TX_RX   2

#define UART_WORDLENGTH_8B 0
#define UART_WORDLENGTH_9B 1

#define UART_PARITY_NONE 0
#define UART_PARITY_EVEN 1
#define UART_PARITY_ODD 2

#define UART_STOPBITS_1 0
#define UART_STOPBITS_2 1

typedef struct{

	uint32_t Baudrate;
	uint32_t Mode;
	uint32_t Parity;
	uint32_t Stopbits;
	uint32_t Wordlength;
}UART_Config_t;

typedef struct{
	USART_TypeDef* Instance;
	UART_Config_t Init;
}UART_Handle_t;

void UART_Init(UART_Handle_t*huart);

void UART_SendChar(UART_Handle_t*huart,char ch);

void UART_SendString(UART_Handle_t*huart,const char*str);

char UART_ReceiveChar(UART_Handle_t*huart);








#endif /* INC_UART_DRIVER_H_ */
