# Systick Delay on STM32

This project demonstrates how to use the SysTick timer on an STM32 microcontroller to create time delays. The SysTick is a simple and efficient timer integrated in the ARM Cortex-M core that can be used to generate precise delays or periodic interrupts.

## Overview

In this project, we will:
- Configure the SysTick timer to generate time delays.
- Use the SysTick timer to create a simple delay function.
- Blink an LED by using the delay function created with the SysTick timer.

### Key Concepts:
- SysTick timer configuration.
- Generating time delays without using traditional `for` loops.
- Basic LED blinking using SysTick-based delays.

## Project Setup

1. **Enable SysTick**: The SysTick timer is a core feature and does not need additional clock enablement.
2. **Configure SysTick for Delay**: We will configure the SysTick timer to generate interrupts or delays in milliseconds.
3. **Create Delay Function**: The SysTick will be used to create a delay function that can be reused in different parts of the code.
4. **LED Blinking**: The delay function will be used to blink an LED connected to the microcontroller.

## Code Breakdown

### 1. SysTick Timer Configuration:
- The SysTick timer is configured with the system clock (typically 16 MHz or 84 MHz for STM32F4 series).
- The reload value is calculated based on the desired delay time (e.g., 1ms).

### 2. Delay Function:
- A delay function is implemented that uses the SysTick timer to create precise delays.
- The delay function waits until the SysTick counter reaches 0 before proceeding, ensuring that the correct amount of time has passed.

### 3. LED Blinking:
- The LED connected to a GPIO pin (e.g., PA5) is toggled on and off at regular intervals using the SysTick-based delay function.

### SysTick Timer Registers:
- **STK_LOAD**: Sets the reload value for the SysTick timer.
- **STK_VAL**: Holds the current count value of the SysTick timer.
- **STK_CTRL**: Controls the status of the SysTick timer (enable/disable, interrupt generation, clock source selection).

## Requirements

- **Hardware**: STM32F4 (or compatible) board, LED connected to PA5 (or another GPIO pin).
- **Software**: STM32CubeIDE, Keil uVision, or any other STM32 development environment.

## How to Run

1. Connect an LED to the appropriate GPIO pin (e.g., PA5).
2. Open the project in your preferred STM32 IDE.
3. Compile and flash the code to your STM32 board.
4. Observe the LED blinking at regular intervals based on the SysTick delay function.

### Example LED Blinking

- The LED will blink on and off with a delay of 1 second (or any time you configure), generated using the SysTick timer.

### Why Use SysTick for Delays?

- **Precise Timing**: The SysTick timer is designed to provide accurate time intervals, more precise than simple loop-based delays.
- **Power Efficient**: SysTick-based delays are more power-efficient, as the CPU can enter low-power states between delays.

## License

This project is open-source and free to use for educational purposes. Feel free to modify and adapt it for your own learning or projects.
