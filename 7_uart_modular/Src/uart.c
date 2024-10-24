#include "uart.h"

#define GPIOAEN			(1U<<0)
#define UART2EN			(1U<<17)

#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)

#define SYS_FREQ		16000000 //Default value
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE	9600	 // Mode Popular value

static void uart_set_baudrate(USART_TypeDef * USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);


void uart2_write(int ch);


int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void uar2_tx_init(void)
{
	/**Configure uart gpio pin**/
	/*Enable clock access to gpioa*/
	RCC ->AHB1ENR |= GPIOAEN;
	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &=~ (1U<<4);
	GPIOA->MODER |= (1U<<5);
	/*Set PA2 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &=~ (1U<<11);





	/**Configure uart module**/
	/*Enable clock access to uart2*/
	RCC->APB1ENR |= UART2EN;

	/*Configure baud rate*/
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE); //Using USART2, CLK and BAUDRATE are defined a default value

	/*Configuure the transfer direction*/
	USART2->CR1 = CR1_TE;

	/*Enable uart module*/
	USART2->CR1 |= CR1_UE; // only want to add the UE bit to the current state of CR1 since we already configured the TE bit
}

void uart2_write(int ch)
{
	/*Make sure the transmit data register is empty*/
	while(!(USART2->SR & SR_TXE)){}

	/*Write to the transmit data register*/
	USART2->DR = (ch & 0xFF); // 0xff since we want to transmit an 8 bit


}

/*Allows this function to be able to work with any UART module*/
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate); //BRR is the baud rate register
}

/*Compute the baud rate*/
static compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}



