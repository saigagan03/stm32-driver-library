#ifndef INC_EEPROM_DRIVER_H_
#define INC_EEPROM_DRIVER_H_

#include "i2c_driver.h"

#define EEPROM_ADDRESS    0x50

void EEPROM_Init(I2C_Handle_t* hi2c);
void EEPROM_WriteByte(I2C_Handle_t* hi2c, uint8_t memory_addr, uint8_t data);
uint8_t EEPROM_ReadByte(I2C_Handle_t* hi2c, uint8_t memory_addr);
uint8_t EEPROM_IsReady(I2C_Handle_t* hi2c);

#endif
