
#include "timer_driver.h"
#include "rcc_driver.h"
#include "gpio_driver.h"

void Timer_Init(Timer_Handle_t*htim){
	if(htim->Instance==TIM2){
	RCC->APB1ENR |= (1<<0);
	}
	else if(htim->Instance==TIM3){
		RCC->APB1ENR |= (1<<1);
	}

	htim->Instance->CR1 &= ~(1<<0);

	htim->Instance->PSC=htim->Init.Prescaler;

	htim->Instance->ARR=htim->Init.Period;

	htim->Instance->CNT=0;

	htim->Instance->EGR |=(1<<0);

	htim->Instance->SR &= ~(1<<0);


}

void Timer_Start(Timer_Handle_t*htim){
	htim->Instance->CR1 |=(1<<0);
}

void Timer_Stop(Timer_Handle_t*htim){
	htim->Instance->CR1 &= ~(1<<0);
}

void Timer_ResetCounter(Timer_Handle_t*htim){
	htim->Instance->CNT=0;
}

uint32_t Timer_GetCounter(Timer_Handle_t*htim){

	uint32_t value=htim->Instance->CNT;
	return value;

}
void Timer_EnableUpdateInterrupt(Timer_Handle_t*htim){
	htim->Instance->DIER |=(1<<0);

	if(htim->Instance==TIM2){
		NVIC_EnableIRQ(TIM2_IRQn);
	}
	else if(htim->Instance==TIM3){
			NVIC_EnableIRQ(TIM3_IRQn);
		}

}

void Timer_PWM_Init(Timer_Handle_t *htim){

//	Enable Timer Clock
	if(htim->Instance==TIM2){
	RCC->APB1ENR |=(1<<0);
	}
	else if(htim->Instance==TIM3){
		RCC->APB1ENR |=(1<<1);
	}
//	Configure TIM2 as AF
	GPIO_AFInit(htim->GPIOx,htim->Pin,htim->AFno);

//	Stop the timer
	htim->Instance->CR1 &= ~(1<<0);

//	Configure the Prescaler
	htim->Instance->PSC=htim->Init.Prescaler;

//	Configure the Period
	htim->Instance->ARR=htim->Init.Period;


//	Configure PWM Mode
	if(htim->Channel==TIMER_CHANNEL_1){
	htim->Instance->CCMR1 &= ~(7 << 4);
	htim->Instance->CCMR1 |=(6<<4);

//	Configure PWM Mode as output
	htim->Instance->CCMR1 &= ~(3<<0);

//	Enable CCR preload
	htim->Instance->CCMR1 |=(1<<3);

//	Set Initial CCR
	htim->Instance->CCR1=0;
	}
	else if(htim->Channel==TIMER_CHANNEL_2){
		htim->Instance->CCMR1 &= ~(7 << 12);
			htim->Instance->CCMR1 |=(6<<12);

		//	Configure PWM Mode as output
			htim->Instance->CCMR1 &= ~(3<<8);

		//	Enable CCR preload
			htim->Instance->CCMR1 |=(1<<11);

		//	Set Initial CCR
			htim->Instance->CCR2=0;
	}
	else if(htim->Channel==TIMER_CHANNEL_3){
		htim->Instance->CCMR2 &= ~(7 << 4);
			htim->Instance->CCMR2 |=(6<<4);

		//	Configure PWM Mode as output
			htim->Instance->CCMR2 &= ~(3<<0);

		//	Enable CCR preload
			htim->Instance->CCMR2 |=(1<<3);

		//	Set Initial CCR
			htim->Instance->CCR3=0;
			}
	else if(htim->Channel==TIMER_CHANNEL_4){
			htim->Instance->CCMR2 &= ~(7 << 12);
				htim->Instance->CCMR2 |=(6<<12);

			//	Configure PWM Mode as output
				htim->Instance->CCMR2 &= ~(3<<8);

			//	Enable CCR preload
				htim->Instance->CCMR2 |=(1<<11);

			//	Set Initial CCR
				htim->Instance->CCR4=0;
		}
	uint32_t cc_enable_bit=4*(htim->Channel-1);

//	Enable the output channel
	htim->Instance->CCER |=(1<<cc_enable_bit);

//	Configure the polarity
	htim->Instance->CCER &= ~(1<<(cc_enable_bit+1));

//	Set the counter to 0
	htim->Instance->CNT=0;

//	Generate Update event
	htim->Instance->EGR |=(1<<0);

//	set uif to 0
	htim->Instance->SR &= ~(1<<0);



}

void Timer_PWM_Start(Timer_Handle_t *htim){
	htim->Instance->CR1 |=(1<<0);
}

void Timer_PWM_Stop(Timer_Handle_t *htim){
	htim->Instance->CR1 &= ~(1<<0);
}

void Timer_PWM_SetDuty(Timer_Handle_t *htim,uint32_t duty){

	uint32_t compare=((duty*(htim->Init.Period+1))/100);
	if(htim->Channel==TIMER_CHANNEL_1){
		htim->Instance->CCR1=compare;
	}
	else if(htim->Channel==TIMER_CHANNEL_2){
		htim->Instance->CCR2=compare;
	}
	else if(htim->Channel==TIMER_CHANNEL_3){
			htim->Instance->CCR3=compare;
		}
	else if(htim->Channel==TIMER_CHANNEL_4){
			htim->Instance->CCR4=compare;
		}
}

void Servo_SetAngle(Timer_Handle_t *htim,uint32_t angle){
	if(angle>180){
		angle=180;
	}
	uint32_t pulse_width=1000+((angle*1000)/180);

	if(htim->Channel==TIMER_CHANNEL_1){
		htim->Instance->CCR1=pulse_width;
	}
	else if(htim->Channel==TIMER_CHANNEL_2){
		htim->Instance->CCR2=pulse_width;

	}
	else if(htim->Channel==TIMER_CHANNEL_3){
		htim->Instance->CCR3=pulse_width;

	}
	else if(htim->Channel==TIMER_CHANNEL_4){
			htim->Instance->CCR4=pulse_width;
	}
}




