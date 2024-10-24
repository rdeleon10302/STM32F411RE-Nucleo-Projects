#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

static void adc_callback();
int sensor_value;
int main(void)
{
	uart2_tx_init();
	pa1_adc_interrupt_init();
	start_conversion();
	while(1)
	{
	}

}

static void adc_callback(void)
{
	sensor_value = ADC1->DR;
	printf("Sensor value: %d\n\r", sensor_value);
}

void ADC_IRQHandler(void)
{
	/*Check for EOC in SR*/
	if((ADC1->SR & SR_EOC) !=0)
	{
		/*Clear EOC*/
		ADC1->SR &=~ SR_EOC;

		// Do something
		adc_callback();
	}
}









