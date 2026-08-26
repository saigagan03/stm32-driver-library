
#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include<stdint.h>
#include"stm32f4xx.h"

#define SPI_CPHA_LOW 0
#define SPI_CPHA_HIGH 1

#define SPI_CPOL_LOW 0
#define SPI_CPOL_HIGH 1

#define SPI_MODE_MASTER 1
#define SPI_MODE_SLAVE 0

#define SPI_BR_DIV2 0
#define SPI_BR_DIV4 1
#define SPI_BR_DIV8 2
#define SPI_BR_DIV16 3
#define SPI_BR_DIV32 4
#define SPI_BR_DIV64 5
#define SPI_BR_DIV128 6
#define SPI_BR_DIV256 7

#define SPI_MSBFIRST 0
#define SPI_LSBFIRST 1

#define SPI_HARDWARE_NSS 0
#define SPI_SOFTWARE_NSS 1

#define SPI_FLAG_RXNE 0
#define SPI_FLAG_TXE 1
#define SPI_FLAG_BSY 7

typedef struct{
	uint8_t Mode;
	uint8_t CPOL;
	uint8_t CPHA;
	uint8_t BaudRatePrescaler;
	uint8_t BitOrder;
	uint8_t NSS;
}SPI_Config_t;

typedef struct{
	SPI_TypeDef* Instance;
	SPI_Config_t Init;
}SPI_Handle_t;


void SPI_Init(SPI_Handle_t *hspi);

void SPI_Transmit(SPI_Handle_t *hspi,uint8_t *buffer,uint32_t length);

uint8_t* SPI_Receive(SPI_Handle_t *hspi,uint8_t *buffer,uint32_t length);

uint8_t* SPI_TransmitReceive(SPI_Handle_t* hspi,uint8_t *t_buffer,uint8_t* r_buffer,uint32_t length);

uint8_t SPI_GetFlagStatus(SPI_Handle_t* hspi,uint8_t flag);



#endif
