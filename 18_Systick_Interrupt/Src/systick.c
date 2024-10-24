#include "stm32f4xx.h"


#define SYSTICK_LOAD_VAL			16000
#define CTRL_ENABLE					(1U<<0)
#define CTRL_CLKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)
#define CTRL_TICKINT				(1U<<1)

#define ONE_SEC_LOAD				16000000	// default frequency of our microcontroller

void systickDelayMs(int delay)
{
	/*Configure systick*/
	/*Reload with number of clks per ms*/
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	/*Clear systick current value register*/
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	for(int i = 0; i < delay; i++)
	{
		/*Wait until the COUNTFLAG is set*/

		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}

	}
	SysTick->CTRL = 0;
}

void systick_1hz_interrupt(void)
{
	/*Reload with number of clocks per second*/
	SysTick->LOAD = ONE_SEC_LOAD - 1;

	/*Clear systick current value register*/
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	/*Enable systick interrupt*/
	SysTick->CTRL |= CTRL_TICKINT;
}







