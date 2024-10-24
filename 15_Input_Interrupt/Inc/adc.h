/*
 * adc.h
 *
 *  Created on: Jul 16, 2024
 *      Author: rdele
 */

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#ifndef ADC_H_
#define ADC_H_

void pa1_adc_init(void);
void start_conversion(void);
uint32_t adc_read(void);


#endif /* ADC_H_ */
