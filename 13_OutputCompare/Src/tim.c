#include "stm32f4xx.h"

#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)

#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)


void tim2_1hz_init(void)
{
	/*Enable clock access to timer 2*/
	RCC->APB1ENR |= TIM2EN;
	/*Set the prescaler value*/
	TIM2->PSC = 1600 - 1;	//subtract 1 since we start from 0
	/*Set the auto-reload value*/
	TIM2->ARR = 10000 - 1;
	/*Clear the timer counter*/
	TIM2->CNT = 0;
	/*Enable the timer*/
	TIM2->CR1 = CR1_CEN;
}

void tim2_pa5_output_compare(void)
{

	/*Enable clock access to PA5*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA5 to alternate function mode*/
	GPIOA->MODER &=~ (1U<<10);
	GPIOA->MODER |= (1U<<11);
	/*Set PA5 alternate function type to TIM2_CH1*/
	GPIOA->AFR[0] |= AFR5_TIM;

	/*Enable clock access to timer 2*/
	RCC->APB1ENR |= TIM2EN;
	/*Set the prescaler value*/
	TIM2->PSC = 1600 - 1;	//subtract 1 since we start from 0
	/*Set the auto-reload value*/
	TIM2->ARR = 10000 - 1;

	/*Set the output compare toggle mode*/
	TIM2->CCMR1 = OC_TOGGLE;
	/*Enable tim2 ch1 in compare mode*/
	TIM2->CCER |= CCER_CC1E;

	/*Clear the timer counter*/
	TIM2->CNT = 0;
	/*Enable the timer*/
	TIM2->CR1 = CR1_CEN;
}
