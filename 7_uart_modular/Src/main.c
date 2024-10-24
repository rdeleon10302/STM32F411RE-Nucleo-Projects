#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "UART.h"

int main(void)
{
	uar2_tx_init();

	while(1)
	{
		printf("Hello from STM32f4........\n\r");

	}
}



