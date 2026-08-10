
#ifndef INC_TIMER_DRIVER_H_
#define INC_TIMER_DRIVER_H_

#include <stdint.h>
#include "stm32f4xx.h"

#define TIMER_CHANNEL_1 1
#define TIMER_CHANNEL_2 2
#define TIMER_CHANNEL_3 3
#define TIMER_CHANNEL_4 4




typedef struct{
	uint32_t Prescaler;
	uint32_t Period;
}Timer_InitTypeDef;

typedef struct{
	TIM_TypeDef*Instance;
	Timer_InitTypeDef Init;
	uint32_t Channel;
	GPIO_TypeDef *GPIOx;
	uint32_t Pin;
	uint32_t AFno;
}Timer_Handle_t;

void Timer_Init(Timer_Handle_t*htim);

void Timer_Start(Timer_Handle_t*htim);

void Timer_Stop(Timer_Handle_t*htim);

void Timer_ResetCounter(Timer_Handle_t*htim);

uint32_t Timer_GetCounter(Timer_Handle_t*htim);

void Timer_EnableUpdateInterrupt(Timer_Handle_t*htim);

void Timer_PWM_Init(Timer_Handle_t *htim);

void Timer_PWM_Start(Timer_Handle_t *htim);

void Timer_PWM_Stop(Timer_Handle_t *htim);

void Timer_PWM_SetDuty(Timer_Handle_t *htim,uint32_t duty);

void Servo_SetAngle(Timer_Handle_t *htim,uint32_t angle);
#endif /* INC_TIMER_DRIVER_H_ */
