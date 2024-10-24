# STM32 Projects Repository

This repository contains multiple STM32 microcontroller projects demonstrating key concepts of embedded systems programming. The projects focus on utilizing GPIO, UART, ADC, Timers, and more, providing a foundation for learning how to interface with different peripherals on the STM32 platform.

## Project Folders

Each folder represents a unique project demonstrating a specific STM32 functionality. Below is a brief description of each project:

### 0_led_toggle_addr
- **Description**: A simple project that toggles an LED using direct memory address manipulation without relying on pre-defined library macros. It gives insight into low-level control of the STM32 hardware.
- **Concepts**: Direct register manipulation, LED toggling.

### 1_led_toggle_addr2_struct
- **Description**: This project builds on the `0_led_toggle_addr` by using structs to organize register access, offering a cleaner and more readable approach to controlling the GPIO.
- **Concepts**: Direct register access, struct-based GPIO control.

### 2_gpio_output
- **Description**: A basic example of using GPIO to control an LED by configuring a pin as an output and toggling its state.
- **Concepts**: GPIO output configuration, LED control.

### 3_gpio_bsrr
- **Description**: Demonstrates the use of the **Bit Set/Reset Register (BSRR)** for efficiently toggling GPIO pins. This method minimizes write conflicts by separating set/reset operations.
- **Concepts**: GPIO bit manipulation using BSRR, efficient pin toggling.

### 4_gpio_input
- **Description**: Shows how to read an input signal from a GPIO pin, such as from a button press, and react accordingly (e.g., turning on an LED).
- **Concepts**: GPIO input reading, button interfacing.

### 5_uart_tx
- **Description**: Demonstrates basic UART transmission by sending data from the microcontroller to a connected terminal.
- **Concepts**: UART configuration, data transmission.

### 6_uart_printf
- **Description**: Extends UART transmission by using `printf()` to send formatted strings over UART, making it easier to print debug information.
- **Concepts**: Formatted output over UART, `printf` usage.

### 7_uart_modular
- **Description**: A modular approach to UART communication, separating the UART setup and data handling logic for better code organization and reusability.
- **Concepts**: Modular programming, UART communication.

### 8_uart_rx
- **Description**: Demonstrates receiving data over UART, allowing the microcontroller to capture input from a terminal or other devices.
- **Concepts**: UART reception, data parsing.

### 9_adc_single_conversion
- **Description**: An ADC (Analog-to-Digital Converter) example that performs a single conversion of an analog input signal.
- **Concepts**: ADC configuration, single-sample conversion.

### 10_adc_continuous_conversion
- **Description**: Configures the ADC for continuous conversion, allowing real-time monitoring of analog inputs.
- **Concepts**: Continuous ADC conversion, real-time data acquisition.

### 11_Systick_delay
- **Description**: Implements a simple delay function using the **Systick** timer, often used for basic timekeeping in embedded systems.
- **Concepts**: Systick timer, delay implementation.

### 12_Timers
- **Description**: Demonstrates the usage of hardware timers for generating precise time intervals or events.
- **Concepts**: Timer configuration, event scheduling.

### 13_OutputCompare
- **Description**: Uses the output compare feature to generate timed output signals based on a timer's count.
- **Concepts**: Output compare, timing control.

### 14_InputCapture
- **Description**: Demonstrates how to use input capture to measure the timing of external events, such as measuring the pulse width of a signal.
- **Concepts**: Input capture, pulse width measurement.

### 15_Input_Interrupt
- **Description**: Shows how to handle GPIO inputs using interrupts, allowing the microcontroller to react to button presses or other inputs asynchronously.
- **Concepts**: GPIO interrupts, asynchronous input handling.

### 16_uart_rx_interrupt
- **Description**: Implements UART data reception using interrupts for efficient, non-blocking communication.
- **Concepts**: UART interrupts, non-blocking communication.

### 16_uart_tx_interrupt
- **Description**: Similar to the `uart_rx_interrupt` project, this one uses interrupts for UART data transmission.
- **Concepts**: UART transmission with interrupts.

### 17_ADC_Interrupt
- **Description**: Handles ADC conversions via interrupts, improving performance by freeing up the CPU while waiting for conversion results.
- **Concepts**: ADC with interrupts, event-driven ADC.

### 18_Systick_Interrupt
- **Description**: Uses the **Systick** timer interrupt to perform time-based tasks, such as periodically toggling an LED or updating a display.
- **Concepts**: Systick interrupts, periodic task execution.

### 19_Timer_Interrupt
- **Description**: Demonstrates generating periodic interrupts using hardware timers, useful for scheduling time-sensitive operations.
- **Concepts**: Timer-based interrupts, scheduling.

### 20_uart_tx_dma
- **Description**: Transmits data over UART using DMA (Direct Memory Access), significantly reducing CPU involvement and improving data transfer efficiency.
- **Concepts**: UART with DMA, efficient data handling.

### 21_I2C_adxl345
- **Description**: Communicates with the ADXL345 accelerometer over I2C, reading data from the sensor and interpreting acceleration.
- **Concepts**: I2C communication, sensor interfacing, ADXL345 accelerometer.

### 22_SPI_adxl345
- **Description**: Similar to the `I2C_adxl345` project but uses SPI for communication with the ADXL345 accelerometer.
- **Concepts**: SPI communication, ADXL345 interfacing.

## Requirements

- **Hardware**: STM32F4 microcontroller (or compatible STM32 series board)
- **Software**: STM32CubeIDE, Keil uVision, or any other STM32 development environment
- **Peripherals**: Depending on the project, some may require additional peripherals such as an LED, push button, or the ADXL345 sensor.

## How to Use

1. Open the project folder you want to explore in your preferred STM32 IDE.
2. Build the project and flash it onto your STM32 board.
3. Follow the instructions in the code comments or refer to each project's description for guidance on hardware connections and functionality.

## License

This repository is open-source and free to use for educational purposes. Feel free to modify and adapt the code for your own projects.
