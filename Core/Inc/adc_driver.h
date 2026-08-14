
#ifndef INC_ADC_DRIVER_H_
#define INC_ADC_DRIVER_H_

#include <stdint.h>
#include"stm32f4xx.h"

#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7
#define ADC_CHANNEL_8 8
#define ADC_CHANNEL_9 9
#define ADC_CHANNEL_10 10
#define ADC_CHANNEL_11 11
#define ADC_CHANNEL_12 12
#define ADC_CHANNEL_13 13
#define ADC_CHANNEL_14 14
#define ADC_CHANNEL_15 15
#define ADC_CHANNEL_16 16
#define ADC_CHANNEL_17 17
#define ADC_CHANNEL_18 18

#define ADC_SampleTime_3_CYCLES 0
#define ADC_SampleTime_15_CYCLES 1
#define ADC_SampleTime_28_CYCLES 2
#define ADC_SampleTime_56_CYCLES 3
#define ADC_SampleTime_84_CYCLES 4
#define ADC_SampleTime_112_CYCLES 5
#define ADC_SampleTime_144_CYCLES 6
#define ADC_SampleTime_480_CYCLES 7

typedef struct{
	uint32_t Conv1_Chno;
	uint32_t Conv2_Chno;
	uint32_t Conv3_Chno;
	uint32_t Conv4_Chno;
	uint32_t Conv5_Chno;
	uint32_t Conv6_Chno;

}ADC_ConChannel_t;

typedef struct{
	uint32_t Conv1_SampleTime;
	uint32_t Conv2_SampleTime;
	uint32_t Conv3_SampleTime;
	uint32_t Conv4_SampleTime;
	uint32_t Conv5_SampleTime;
	uint32_t Conv6_SampleTime;

}ADC_SampleTime_t;

typedef struct{
	GPIO_TypeDef* Conv1_GPIOx;
	uint16_t Conv1_Pin;
	GPIO_TypeDef* Conv2_GPIOx;
	uint16_t Conv2_Pin;
	GPIO_TypeDef* Conv3_GPIOx;
	uint16_t Conv3_Pin;
	GPIO_TypeDef* Conv4_GPIOx;
	uint16_t Conv4_Pin;
	GPIO_TypeDef* Conv5_GPIOx;
	uint16_t Conv5_Pin;
	GPIO_TypeDef* Conv6_GPIOx;
	uint16_t Conv6_Pin;
}ADC_GPIO_t;

typedef struct{
	ADC_TypeDef* Instance;
	ADC_SampleTime_t Init1;
	ADC_ConChannel_t Init;
	ADC_GPIO_t Init2;
	uint16_t Conversion_no;
}ADC_Handle_t;


void ADC_Init(ADC_Handle_t* hadc);

void ADC_Start(ADC_Handle_t* hadc);

void ADC_Read(ADC_Handle_t* hadc,uint16_t *buffer);




#endif /* INC_ADC_DRIVER_H_ */
