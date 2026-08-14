
#include"adc_driver.h"
#include"gpio_driver.h"
static void ADC_SetupSQ(ADC_Handle_t* hadc,uint16_t sequence,uint32_t channel){
	uint16_t shift=5*(sequence-1);
	hadc->Instance->SQR3 &= ~(0x1F<<shift);
	hadc->Instance->SQR3 |=(channel<<shift);
}
static void ADC_SetSampleTime(ADC_Handle_t* hadc,uint32_t channel,uint32_t sampleTime){

	uint32_t shift;
	if(channel<=9){
		shift=3*channel;
		hadc->Instance->SMPR2 &= ~(7<<shift);
		hadc->Instance->SMPR2 |=(sampleTime<<shift);
	}
	else{
		shift=3*(channel-10);
		hadc->Instance->SMPR1 &= ~(7<<shift);
		hadc->Instance->SMPR1 |=(sampleTime<<shift);
	}
}
static void ADC_EnableInternalChannel(uint32_t channel)
{
    if(channel == ADC_CHANNEL_17 || channel==ADC_CHANNEL_16)
    {
        // Enable VREFINT
        ADC->CCR |= (1 << 23);
    }
}
void ADC_Init(ADC_Handle_t* hadc){

	if(hadc->Conversion_no==0 || hadc->Conversion_no>6){
			return;
		}
//	ADC->CCR &= ~(3 << 16);
//	ADC->CCR |=  (1 << 16);

//	Enabling the adc peripheral clock
	if(hadc->Instance==ADC1){
		RCC->APB2ENR |=(1<<8);
	}
	else if(hadc->Instance==ADC2){
		RCC->APB2ENR |=(1<<9);
	}
	else if(hadc->Instance==ADC3){
		RCC->APB2ENR |=(1<<10);
	}

//	Configuring GPIO pin as analog mode
	if(hadc->Conversion_no>=1){
		if(hadc->Init.Conv1_Chno<=ADC_CHANNEL_15){
		GPIO_Analog_Init(hadc->Init2.Conv1_GPIOx,hadc->Init2.Conv1_Pin);
		}
	}
	if(hadc->Conversion_no>=2){
		if(hadc->Init.Conv2_Chno<=ADC_CHANNEL_15){
			GPIO_Analog_Init(hadc->Init2.Conv2_GPIOx,hadc->Init2.Conv2_Pin);
		}
		}
	if(hadc->Conversion_no>=3){
		if(hadc->Init.Conv3_Chno<=ADC_CHANNEL_15){
			GPIO_Analog_Init(hadc->Init2.Conv3_GPIOx,hadc->Init2.Conv3_Pin);
		}
	}
	if(hadc->Conversion_no>=4){
		if(hadc->Init.Conv4_Chno<=ADC_CHANNEL_15){
			GPIO_Analog_Init(hadc->Init2.Conv4_GPIOx,hadc->Init2.Conv4_Pin);
		}
	}
	if(hadc->Conversion_no>=5){
		if(hadc->Init.Conv5_Chno<=ADC_CHANNEL_15){
			GPIO_Analog_Init(hadc->Init2.Conv5_GPIOx,hadc->Init2.Conv5_Pin);
		}
	}
	if(hadc->Conversion_no>=6){
		if(hadc->Init.Conv6_Chno<=ADC_CHANNEL_15){
			GPIO_Analog_Init(hadc->Init2.Conv6_GPIOx,hadc->Init2.Conv6_Pin);
		}
	}

//	Configuring the continuos conversion bit
	if(hadc->Conversion_no==1){
		hadc->Instance->CR2 &= ~(1<<1);
	}

	else if(hadc->Conversion_no>1){
		hadc->Instance->CR2 |=(1<<1);
	}

//	Setting the no of conversions
	uint16_t l=(hadc->Conversion_no)-1;
		hadc->Instance->SQR1 &= ~(0xF<<20);
		hadc->Instance->SQR1 |=(l<<20);



//	Selecting the channel no
		if(hadc->Conversion_no>=1){
			ADC_SetupSQ(hadc,1,hadc->Init.Conv1_Chno);
			ADC_EnableInternalChannel(hadc->Init.Conv1_Chno);
		}
		if(hadc->Conversion_no>=2){
					ADC_SetupSQ(hadc,2,hadc->Init.Conv2_Chno);
				}
		if(hadc->Conversion_no>=3){
					ADC_SetupSQ(hadc,3,hadc->Init.Conv3_Chno);
				}
		if(hadc->Conversion_no>=4){
					ADC_SetupSQ(hadc,4,hadc->Init.Conv4_Chno);
				}
		if(hadc->Conversion_no>=5){
					ADC_SetupSQ(hadc,5,hadc->Init.Conv5_Chno);
				}
		if(hadc->Conversion_no>=6){
					ADC_SetupSQ(hadc,6,hadc->Init.Conv6_Chno);
				}

//	setting the sample time

		if(hadc->Conversion_no>=1){
			ADC_SetSampleTime(hadc,hadc->Init.Conv1_Chno,hadc->Init1.Conv1_SampleTime);
		}
		if(hadc->Conversion_no>=2){
			ADC_SetSampleTime(hadc,hadc->Init.Conv2_Chno,hadc->Init1.Conv2_SampleTime);
		}
		if(hadc->Conversion_no>=3){
					ADC_SetSampleTime(hadc,hadc->Init.Conv3_Chno,hadc->Init1.Conv3_SampleTime);
				}
		if(hadc->Conversion_no>=4){
					ADC_SetSampleTime(hadc,hadc->Init.Conv4_Chno,hadc->Init1.Conv4_SampleTime);
				}
		if(hadc->Conversion_no>=5){
					ADC_SetSampleTime(hadc,hadc->Init.Conv5_Chno,hadc->Init1.Conv5_SampleTime);
				}
		if(hadc->Conversion_no>=6){
					ADC_SetSampleTime(hadc,hadc->Init.Conv6_Chno,hadc->Init1.Conv6_SampleTime);
				}

//		enable the adc
		hadc->Instance->CR2 |=(1<<0);




}

void ADC_Start(ADC_Handle_t* hadc){

//	enable swstart
	hadc->Instance->CR2 |=(1<<30);
}

void ADC_Read(ADC_Handle_t* hadc,uint16_t* buffer){
	for(uint16_t i=0;i<hadc->Conversion_no;i++){
	while(!(hadc->Instance->SR & (1<<1))){
//		wait till eoc becomes1
	}

	buffer[i]=hadc->Instance->DR;

	}

}


