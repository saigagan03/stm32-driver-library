#include"spi_driver.h"
#include"gpio_driver.h"

void SPI_Init(SPI_Handle_t *hspi){

//	Enabling SPI Peripheral clock
//	Configuring GPIO pins as AF mode
	if(hspi->Instance==SPI1){
		RCC->APB2ENR |=(1<<12);
		GPIO_AFInit(GPIOA,GPIO_PIN_5,5);
		GPIO_AFInit(GPIOA,GPIO_PIN_6,5);
		GPIO_AFInit(GPIOA,GPIO_PIN_7,5);

		GPIOA->OSPEEDR &= ~(3<<10);
		GPIOA->OSPEEDR |= (2<<10);

		GPIOA->OSPEEDR &= ~(3<<12);
		GPIOA->OSPEEDR |= (2<<12);

		GPIOA->OSPEEDR &= ~(3<<14);
		GPIOA->OSPEEDR |= (2<<14);
	}
	else if(hspi->Instance==SPI2){
		RCC->APB1ENR |=(1<<14);
		GPIO_AFInit(GPIOB,GPIO_PIN_13,5);
		GPIO_AFInit(GPIOB,GPIO_PIN_14,5);
		GPIO_AFInit(GPIOB,GPIO_PIN_15,5);

		GPIOB->OSPEEDR &= ~(3<<26);
		GPIOB->OSPEEDR |= (2<<26);

		GPIOB->OSPEEDR &= ~(3<<28);
		GPIOB->OSPEEDR |= (2<<28);

		GPIOB->OSPEEDR &= ~(3<<30);
		GPIOB->OSPEEDR |= (2<<30);


	}
	else if(hspi->Instance==SPI3){
		RCC->APB1ENR |=(1<<15);

		GPIO_AFInit(GPIOB,GPIO_PIN_3,6);
		GPIO_AFInit(GPIOB,GPIO_PIN_4,6);
		GPIO_AFInit(GPIOB,GPIO_PIN_5,6);

		GPIOB->OSPEEDR &= ~(3<<6);
		GPIOB->OSPEEDR |= (2<<6);

		GPIOB->OSPEEDR &= ~(3<<8);
		GPIOB->OSPEEDR |= (2<<8);

		GPIOB->OSPEEDR &= ~(3<<10);
		GPIOB->OSPEEDR |= (2<<10);
	}



//	Disable SPI Clock
	hspi->Instance->CR1 &= ~(1<<6);

//	Configuring Master mode
	hspi->Instance->CR1 &= ~(1<<2);
	hspi->Instance->CR1 |=(hspi->Init.Mode<<2);



//	Configuring CPOL
	hspi->Instance->CR1 &= ~(1<<1);
	hspi->Instance->CR1 |=(hspi->Init.CPOL<<1);


//	Configuring CPHA
	hspi->Instance->CR1 &= ~(1<<0);
	hspi->Instance->CR1 |=(hspi->Init.CPHA<<0);


//	Configuring Baudrate Presacaler
	hspi->Instance->CR1 &= ~(7<<3);
	hspi->Instance->CR1 |=(hspi->Init.BaudRatePrescaler<<3);

//	Configuring bit order
	hspi->Instance->CR1 &= ~(1<<7);
	hspi->Instance->CR1 |=(hspi->Init.BitOrder<<7);

//	Configuring NSS
	if(hspi->Init.NSS==SPI_HARDWARE_NSS){
		hspi->Instance->CR1 &= ~(1<<9);
	}

	else if(hspi->Init.NSS==SPI_SOFTWARE_NSS){
		hspi->Instance->CR1 |=(1<<9);
		hspi->Instance->CR1 |=(1<<8);
	}

//	Enable the SPE
	hspi->Instance->CR1 |=(1<<6);




}
uint8_t SPI_GetFlagStatus(SPI_Handle_t* hspi,uint8_t flag){
		return ((hspi->Instance->SR & (1<<flag))!=0);

}
void SPI_Transmit(SPI_Handle_t *hspi,uint8_t *buffer,uint32_t length){
	uint32_t i=0;
	while(i<length){
		while(SPI_GetFlagStatus(hspi,SPI_FLAG_TXE)==0){

			}
		hspi->Instance->DR=buffer[i];
		while(SPI_GetFlagStatus(hspi, SPI_FLAG_RXNE) == 0)
		{
		}

		(void)hspi->Instance->DR;
		i++;
	}
	while(SPI_GetFlagStatus(hspi,SPI_FLAG_BSY)!=0){

	}
}

uint8_t* SPI_Receive(SPI_Handle_t *hspi,uint8_t *buffer,uint32_t length){
	uint32_t i=0;
	while(i<length){
		while(SPI_GetFlagStatus(hspi,SPI_FLAG_TXE)==0){

		}
		hspi->Instance->DR=0XFF;
		while(SPI_GetFlagStatus(hspi,SPI_FLAG_RXNE)==0){

		}
		buffer[i]=hspi->Instance->DR;
		i++;

	}
	return buffer;

}

uint8_t* SPI_TransmitReceive(SPI_Handle_t* hspi,uint8_t *t_buffer,uint8_t* r_buffer,uint32_t length){
	uint32_t i=0;
	while(i<length){
		while(SPI_GetFlagStatus(hspi,SPI_FLAG_TXE)==0){

		}
		hspi->Instance->DR=t_buffer[i];

		while(SPI_GetFlagStatus(hspi,SPI_FLAG_RXNE)==0);
		r_buffer[i]=hspi->Instance->DR;
		i++;
	}
	while(SPI_GetFlagStatus(hspi,SPI_FLAG_BSY)!=0);
	return r_buffer;

}



