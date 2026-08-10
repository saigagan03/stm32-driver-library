
#include"delay.h"
#include"gpio_driver.h"
#include"rcc_driver.h"

void Delay_ms(Timer_Handle_t *htim,uint32_t delay){
	uint32_t freq;
	uint32_t timer_c=RCC_GetPCLK1Freq();
	freq=(2*timer_c/(htim->Init.Prescaler+1));
	uint32_t req_time=(freq*delay)/1000;

	Timer_ResetCounter(htim);
	Timer_Start(htim);

	while(Timer_GetCounter(htim)<(req_time)){

	}
	Timer_Stop(htim);

}
