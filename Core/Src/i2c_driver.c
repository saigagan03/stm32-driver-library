#include"i2c_driver.h"
#include"gpio_driver.h"
#include"rcc_driver.h"
void I2C_Init(I2C_Handle_t* hi2c){
	if(hi2c->Instance==I2C1){
//		Enabling the peripheral clock
		RCC->APB1ENR |=(1<<21);
//		Configuring gpio pins as af
		GPIO_AFInit(GPIOB,GPIO_PIN_6,4);
		GPIO_AFInit(GPIOB,GPIO_PIN_7,4);
//		Configuring pins as open drain outputs
		GPIOB->OTYPER |=(1<<6);
		GPIOB->OTYPER |=(1<<7);
//		Configuring pull up
		GPIOB->PUPDR &= ~(3<<12);
		GPIOB->PUPDR |= (1<<12);
		GPIOB->PUPDR &= ~(3<<14);
		GPIOB->PUPDR |= (1<<14);
//		Configuring output speed
		GPIOB->OSPEEDR &= ~(3<<12);
		GPIOB->OSPEEDR |= (2<<12);
		GPIOB->OSPEEDR &= ~(3<<14);
		GPIOB->OSPEEDR |= (2<<14);
	}
	else if(hi2c->Instance==I2C2){
	//		Enabling the peripheral clock
			RCC->APB1ENR |=(1<<22);
	//		Configuring gpio pins as af
			GPIO_AFInit(GPIOB,GPIO_PIN_10,4);
			GPIO_AFInit(GPIOB,GPIO_PIN_11,4);
	//		Configuring pins as open drain outputs
			GPIOB->OTYPER |=(1<<10);
			GPIOB->OTYPER |=(1<<11);
	//		Configuring pull up
			GPIOB->PUPDR &= ~(3<<20);
			GPIOB->PUPDR |= (1<<20);
			GPIOB->PUPDR &= ~(3<<22);
			GPIOB->PUPDR |= (1<<22);
	//		Configuring output speed
			GPIOB->OSPEEDR &= ~(3<<20);
			GPIOB->OSPEEDR |= (2<<20);
			GPIOB->OSPEEDR &= ~(3<<22);
			GPIOB->OSPEEDR |= (2<<22);
	}
	else if(hi2c->Instance==I2C3){
	//		Enabling the peripheral clock
			RCC->APB1ENR |=(1<<23);
	//		Configuring gpio pins as af
			GPIO_AFInit(GPIOA,GPIO_PIN_8,4);
			GPIO_AFInit(GPIOC,GPIO_PIN_9,4);
	//		Configuring pins as open drain outputs
			GPIOA->OTYPER |=(1<<8);
			GPIOC->OTYPER |=(1<<9);
	//		Configuring pull up
			GPIOA->PUPDR &= ~(3<<16);
			GPIOA->PUPDR |= (1<<16);
			GPIOC->PUPDR &= ~(3<<18);
			GPIOC->PUPDR |= (1<<18);
	//		Configuring output speed
			GPIOA->OSPEEDR &= ~(3<<16);
			GPIOA->OSPEEDR |= (2<<16);
			GPIOC->OSPEEDR &= ~(3<<18);
			GPIOC->OSPEEDR |= (2<<18);
	}

//	Disabling the i2c pe bit
	hi2c->Instance->CR1 &= ~(1<<0);

//	Configuring CR2
	uint32_t pclk1=RCC_GetPCLK1Freq();
	hi2c->Instance->CR2 &= ~(0x3F<<0);
	hi2c->Instance->CR2 |=(pclk1/1000000);

//	Configuring CCR
	if(hi2c->Init.ClockSpeed==I2C_CLOCK_STANDARD){
		hi2c->Instance->CCR &= ~(1<<15);
		uint32_t ccr=(pclk1/(2*(hi2c->Init.ClockSpeed)));
		hi2c->Instance->CCR &= ~(0xFFF);
		hi2c->Instance->CCR |=ccr;

	}
	else if(hi2c->Init.ClockSpeed==I2C_CLOCK_FAST){
		hi2c->Instance->CCR |= (1<<15);
		if(hi2c->Init.DutyCycle==I2C_DUTY_2){
			hi2c->Instance->CCR &= ~(1<<14);
			uint32_t ccr=(pclk1/(3*(hi2c->Init.ClockSpeed)));
			hi2c->Instance->CCR &= ~(0xFFF);
			hi2c->Instance->CCR |=ccr;


		}
		else if(hi2c->Init.DutyCycle==I2C_DUTY_16_9){
			hi2c->Instance->CCR |= (1<<14);
			uint32_t ccr=(pclk1/(25*(hi2c->Init.ClockSpeed)));
			hi2c->Instance->CCR &= ~(0xFFF);
			hi2c->Instance->CCR |=ccr;

		}


	}
//	Configuring TRISE
	if(hi2c->Init.ClockSpeed==I2C_CLOCK_STANDARD){
	uint32_t trise=(pclk1/1000000)+1;
	hi2c->Instance->TRISE=trise;
	}
	else if(hi2c->Init.ClockSpeed==I2C_CLOCK_FAST){
		uint32_t trise=(pclk1*300/1000000)+1;
		hi2c->Instance->TRISE=trise;
	}

//	enabling the pe bit
	hi2c->Instance->CR1 |=(1<<0);

}
void I2C_Start(I2C_Handle_t* hi2c){
	hi2c->Instance->CR1 |=(1<<8);
}

void I2C_Stop(I2C_Handle_t* hi2c){
	hi2c->Instance->CR1 |=(1<<9);
}

uint8_t I2C_CheckAddress(I2C_Handle_t* hi2c, uint8_t slave_addr){

	volatile uint32_t temp;

	I2C_Start(hi2c);

	while(!(hi2c->Instance->SR1 & (1<<0)));

	hi2c->Instance->DR=(slave_addr<<1);

	while(!(hi2c->Instance->SR1 & ((1<<1) | (1<<10))));

	if(hi2c->Instance->SR1 & (1<<10)){

		temp=hi2c->Instance->SR1;

		hi2c->Instance->CR1 |= (1<<9);

		return 0;
	}

	temp=hi2c->Instance->SR1;
	temp=hi2c->Instance->SR2;

	I2C_Stop(hi2c);

	return 1;
}
void I2C_Transmit(I2C_Handle_t* hi2c,uint8_t data,uint8_t slave_addr,uint8_t reg_addr){
	I2C_Start(hi2c);
	while(!(hi2c->Instance->SR1 & (1<<0)));

	hi2c->Instance->DR=((slave_addr<<1)|0);
	while(!(hi2c->Instance->SR1 & (1<<1)));
	volatile uint32_t temp;
	temp = hi2c->Instance->SR1;
	temp = hi2c->Instance->SR2;

	hi2c->Instance->DR=reg_addr;
	while(!(hi2c->Instance->SR1 & (1<<7)));

	hi2c->Instance->DR=data;
	while(!(hi2c->Instance->SR1 & (1<<2)));

	I2C_Stop(hi2c);


}
uint8_t I2C_Receive(I2C_Handle_t* hi2c,uint8_t slave_addr,uint8_t reg_addr){
	I2C_Start(hi2c);
	while(!(hi2c->Instance->SR1 & (1<<0)));
	hi2c->Instance->DR=((slave_addr<<1)|0);
	while(!(hi2c->Instance->SR1 & (1<<1)));
	volatile uint32_t temp;
	temp = hi2c->Instance->SR1;
	temp = hi2c->Instance->SR2;

	hi2c->Instance->DR=reg_addr;
	while(!(hi2c->Instance->SR1 & (1<<7)));

	I2C_Start(hi2c);
	while(!(hi2c->Instance->SR1 & (1<<0)));
	hi2c->Instance->DR=((slave_addr<<1)| 1);
	while(!(hi2c->Instance->SR1 & (1<<1)));

	hi2c->Instance->CR1 &= ~(1<<10);

	temp = hi2c->Instance->SR1;
	temp = hi2c->Instance->SR2;

	I2C_Stop(hi2c);
	uint8_t data;
	while(!(hi2c->Instance->SR1 & (1<<6)));
	data=hi2c->Instance->DR;


	hi2c->Instance->CR1 |= (1<<10);
	return data;


}
