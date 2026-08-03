

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_
#define MY_GPIO_NOPULL    0
#define MY_GPIO_PULLUP    1
#define MY_GPIO_PULLDOWN  2
#define GPIO_RISING_EDGE 0
#define GPIO_FALLING_EDGE 1
#define GPIO_BOTH_EDGE 2

#include "main.h"
void GPIO_WritePin(GPIO_TypeDef*GPIOx,uint16_t Pin,uint8_t value);

uint8_t GPIO_ReadPin(GPIO_TypeDef*GPIOx,uint16_t Pin);

void GPIO_TogglePin(GPIO_TypeDef*GPIOx,uint16_t Pin);

void GPIO_Output_Init(GPIO_TypeDef*GPIOx,uint16_t Pin);

void GPIO_Input_Init(GPIO_TypeDef*GPIOx,uint16_t Pin,uint8_t Pulltype);

void GPIO_Interrupt_Init(GPIO_TypeDef*GPIOx,uint16_t Pin,uint8_t TriggerType);

void GPIO_AFInit(GPIO_TypeDef*GPIOx,uint16_t TX_Pin,uint8_t AFNumber);

#endif /* INC_GPIO_DRIVER_H_ */
