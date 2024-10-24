# LED Toggle with Direct Memory Addressing

This project demonstrates how to toggle an LED on an STM32 microcontroller using direct memory address manipulation. It bypasses the usual HAL (Hardware Abstraction Layer) libraries, offering insight into how hardware can be controlled at a low level by directly interacting with the device's registers.

## Overview

In this project, we will:
- Enable the clock for GPIOA.
- Configure PA5 as an output pin.
- Toggle the LED connected to PA5 using direct register access.

By using direct memory addressing, the code illustrates the basic principles of hardware control and provides a foundation for deeper understanding of embedded systems programming.

## Code Description

- **Enable Clock**: The clock for GPIOA is enabled by setting the appropriate bit in the RCC AHB1 peripheral clock enable register.
- **GPIO Configuration**: PA5 is configured as an output pin by directly modifying the GPIOA MODER register.
- **LED Toggling**: The LED connected to PA5 is toggled by writing directly to the GPIOA Output Data Register (ODR).

### Key Concepts:
- Direct memory register manipulation.
- Basic GPIO setup and output control.
- No reliance on STM32 HAL libraries.

### Registers Used:
- **RCC_AHB1ENR**: Enables the clock for GPIOA.
- **GPIOA_MODER**: Configures the mode of GPIO pins (input/output).
- **GPIOA_ODR**: Controls the output data on GPIO pins (setting/resetting).

### Main Loop:
The code enters an infinite loop where it toggles the LED by writing to the ODR register with a simple delay implemented using a `for` loop.

## Requirements

- **Hardware**: STM32F4 (or compatible) board, LED connected to PA5.
- **Software**: STM32CubeIDE, Keil uVision, or any other STM32 development environment.

## How to Run

1. Connect an LED to PA5 of your STM32 board.
2. Open the project in your preferred STM32 IDE.
3. Compile and flash the code to your board.
4. Observe the LED blinking at regular intervals.

## Explanation of Direct Register Access

This project does not use the STM32 HAL or CMSIS libraries to configure the GPIO pin. Instead, it directly manipulates the memory-mapped registers using specific addresses.

- To enable the clock for GPIOA, the `RCC->AHB1ENR` register is modified.
- To set the pin mode for PA5, the `GPIOA->MODER` register is accessed directly.
- To toggle the LED, the `GPIOA->ODR` register is updated.

This approach, while less abstracted, gives more control over the hardware and helps you learn how peripherals are configured at a low level.

## License

This project is open-source and free to use for educational purposes. Feel free to modify and adapt it for your own learning or projects.
