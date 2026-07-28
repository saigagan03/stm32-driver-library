#include"gpio_driver.h"
void GPIO_WritePin(GPIO_TypeDef*GPIOx,uint16_t Pin,uint8_t value){
	if(value){
		GPIOx->ODR |=Pin;
	}
	else{
		GPIOx->ODR &= ~Pin;
	}
}

uint8_t  GPIO_ReadPin(GPIO_TypeDef*GPIOx,uint16_t Pin){
	if(GPIOx->IDR & Pin){
		return 1;
	}
	else{
		return 0;
	}
}

void GPIO_TogglePin(GPIO_TypeDef*GPIOx,uint16_t Pin){
	GPIOx->ODR ^=Pin;
}
void GPIO_Output_Init(GPIO_TypeDef*GPIOx,uint16_t Pin){
	uint8_t pinnumber=0;
	uint16_t tempPin=Pin;
	while(tempPin >1){
		pinnumber++;
		tempPin>>=1;
	}
	if(GPIOx==GPIOA){
		RCC->AHB1ENR |=(1<<0);
	}
	else if(GPIOx==GPIOB){
		RCC->AHB1ENR |=(1<<1);
	}
	else if(GPIOx==GPIOC){
		RCC->AHB1ENR |=(1<<2);
	}
	GPIOx->MODER &= ~(3<<(2*pinnumber));
	GPIOx->MODER |= (1<<(2*pinnumber));
	GPIOx->OTYPER &= ~Pin;
	GPIOx->OSPEEDR &= ~(3<<(2*pinnumber));



}
void GPIO_Input_Init(GPIO_TypeDef*GPIOx,uint16_t Pin,uint8_t Pulltype){
	uint8_t pinnumber=0;
		uint16_t tempPin=Pin;
		while(tempPin >1){
			pinnumber++;
			tempPin>>=1;
		}
		if(GPIOx==GPIOA){
				RCC->AHB1ENR |=(1<<0);
			}
			else if(GPIOx==GPIOB){
				RCC->AHB1ENR |=(1<<1);
			}
			else if(GPIOx==GPIOC){
				RCC->AHB1ENR |=(1<<2);
			}
		GPIOx->MODER &= ~(3<<(2*pinnumber));
		GPIOx->PUPDR &= ~(3<<(2*pinnumber));
		GPIOx->PUPDR |= (Pulltype<<(2*pinnumber));

}
void GPIO_Interrupt_Init(GPIO_TypeDef*GPIOx,uint16_t Pin,uint8_t TriggerType){
	uint8_t pinNumber=0;
	uint16_t tempPin=Pin;
	while(tempPin>1){
		pinNumber++;
		tempPin>>=1;
	}
	if(GPIOx==GPIOA){
					RCC->AHB1ENR |=(1<<0);
			    }
    else if(GPIOx==GPIOB){
					RCC->AHB1ENR |=(1<<1);
				}
    else if(GPIOx==GPIOC){
					RCC->AHB1ENR |=(1<<2);
				}
	RCC->APB2ENR |=(1<<14);
	uint8_t extiIndex=pinNumber/4;
	uint8_t shift=4*(pinNumber%4);
	SYSCFG->EXTICR[extiIndex] &= ~(0xF<<shift);
	if(GPIOx==GPIOA){
		SYSCFG->EXTICR[extiIndex] |=(0x0<<shift);
	}
	else if(GPIOx==GPIOB){
		SYSCFG->EXTICR[extiIndex] |=(0x1<<shift);
	}
	else if(GPIOx==GPIOC){
			SYSCFG->EXTICR[extiIndex] |=(0x2<<shift);
	}
	EXTI->IMR |=(1<<pinNumber);
	if(TriggerType==GPIO_FALLING_EDGE){
		EXTI->FTSR |=(1<<pinNumber);
		EXTI->RTSR &= ~(1<<pinNumber);
	}
	else if(TriggerType==GPIO_RISING_EDGE){
		EXTI->RTSR |=(1<<pinNumber);
		EXTI->FTSR &= ~(1<<pinNumber);
	}
	else if(TriggerType==GPIO_BOTH_EDGE){
		EXTI->RTSR |=(1<<pinNumber);
		EXTI->FTSR |= (1<<pinNumber);

	}
	if(pinNumber==0){
		NVIC_EnableIRQ(EXTI0_IRQn);
	}

	else if(pinNumber==1){
		NVIC_EnableIRQ(EXTI1_IRQn);
	}
	else if(pinNumber==2){
			NVIC_EnableIRQ(EXTI2_IRQn);
		}
	else if(pinNumber==3){
			NVIC_EnableIRQ(EXTI3_IRQn);
		}
	else if(pinNumber==4){
			NVIC_EnableIRQ(EXTI4_IRQn);
		}
	else if(pinNumber>=5 && pinNumber<=9){
		NVIC_EnableIRQ(EXTI9_5_IRQn);
	}
	else if(pinNumber>=10 && pinNumber<=15){
		NVIC_EnableIRQ(EXTI15_10_IRQn);
	}


}
