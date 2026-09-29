
#ifndef INC_I2C_DRIVER_H_
#define INC_I2C_DRIVER_H_

#include<stdint.h>
#include"stm32f4xx.h"

#define I2C_CLOCK_STANDARD 100000
#define I2C_CLOCK_FAST 400000

#define I2C_ADDRESSING_MODE_7_BIT 0
#define I2C_ADDRESSING_MODE_10_BIT 1

#define I2C_DUTY_2 0
#define I2C_DUTY_16_9 1



typedef struct{
	uint32_t ClockSpeed;
	uint32_t AddressingMode;
	uint32_t DutyCycle;
}I2C_Config_t;

typedef struct{
	I2C_TypeDef* Instance;
	I2C_Config_t Init;
}I2C_Handle_t;

void I2C_Init(I2C_Handle_t* hi2c);

void I2C_Start(I2C_Handle_t* hi2c);

void I2C_Stop(I2C_Handle_t* hi2c);

uint8_t I2C_CheckAddress(I2C_Handle_t* hi2c, uint8_t slave_addr);

void I2C_Transmit(I2C_Handle_t* hi2c,uint8_t data,uint8_t slave_addr,uint8_t reg_addr);

uint8_t I2C_Receive(I2C_Handle_t* hi2c,uint8_t slave_addr,uint8_t reg_addr);



#endif /* INC_I2C_DRIVER_H_ */
