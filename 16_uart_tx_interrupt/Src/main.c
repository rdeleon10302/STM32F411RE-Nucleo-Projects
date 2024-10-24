#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"


#define GPIOAEN				   (1U<<0)
#define GPIOA_5				   (1U<<5)

#define LED_PIN				   GPIOA_5

// Buffer and Indexes
#define TX_BUFFER_SIZE      256
static uint8_t tx_buffer[TX_BUFFER_SIZE];
static uint16_t tx_buffer_head = 0;
static uint16_t tx_buffer_tail = 0;

void uart2_tx_interrupt_init(void);
void uart2_send_byte(uint8_t byte);
void uart2_send_string(const char* str);

int main(void)
{

	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	// 3. Initialize UART2 for TX with interrupts
	uart2_tx_interrupt_init();

	// 4. Example usage: Send a string
	uart2_send_string("Hello, World!\n");
	while(1)
	{

	}

}

void uart2_send_byte(uint8_t byte)
{
    uint16_t next_head = (tx_buffer_head + 1) % TX_BUFFER_SIZE;
    while (next_head == tx_buffer_tail)
    {
        // Buffer is full, wait until space is available
    }
    tx_buffer[tx_buffer_head] = byte;
    tx_buffer_head = next_head;

    // Enable TXE interrupt if not already enabled
    USART2->CR1 |= USART_CR1_TXEIE;
}

void uart2_send_string(const char* str)
{
    while (*str)
    {
        uart2_send_byte((uint8_t)*str++);
    }
}
static void tx_callback(void)
{
    // Check if TXE (Transmit Data Register Empty) flag is set
    if (USART2->SR & USART_SR_TXE)
    {
        // Check if there is data to send
        if (tx_buffer_head != tx_buffer_tail)
        {
            USART2->DR = tx_buffer[tx_buffer_tail];  // Send data
            tx_buffer_tail = (tx_buffer_tail + 1) % TX_BUFFER_SIZE;  // Update buffer index
        }
        else
        {
            // Disable TXE interrupt if buffer is empty
            USART2->CR1 &= ~USART_CR1_TXEIE;
        }
    }
}

void USART2_IRQHandler(void)
{
    // Check if the TXE (Transmit Data Register Empty) flag is set
    if (USART2->SR & USART_SR_TXE)
    {
        // Call the static callback function to handle the TXE event
        tx_callback();
    }
}





