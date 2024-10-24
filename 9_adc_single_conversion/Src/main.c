#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"


int sensor_value;
int main(void)
{
	uart2_tx_init();
	pa1_adc_init();

	while(1)
	{
		start_conversion();
		sensor_value = adc_read();
		printf("Sensor value: %d\n\r", sensor_value);
	}

}




