#include "eeprom_driver.h"

void EEPROM_Init(I2C_Handle_t* hi2c){

}

uint8_t EEPROM_IsReady(I2C_Handle_t* hi2c){

	while(!I2C_CheckAddress(hi2c, EEPROM_ADDRESS));

	return 1;
}

void EEPROM_WriteByte(I2C_Handle_t* hi2c, uint8_t memory_addr, uint8_t data){

	I2C_Transmit(hi2c, data, EEPROM_ADDRESS, memory_addr);

	EEPROM_IsReady(hi2c);

}

uint8_t EEPROM_ReadByte(I2C_Handle_t* hi2c, uint8_t memory_addr){

	uint8_t data;

	data=I2C_Receive(hi2c, EEPROM_ADDRESS, memory_addr);

	return data;
}
