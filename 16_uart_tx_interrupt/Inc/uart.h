

#ifndef UART_H_
#define UART_H_
#include <stdint.h>

#include "stm32f4xx.h"

void uart2_tx_init(void);
char uart2_read(void);
void uart2_rxtx_init(void);
void uart2_tx_interrupt_init(void);


#define SR_TXE			(1U<<7)


#endif /* UART_H_ */
