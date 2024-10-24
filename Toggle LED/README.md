This project demonstrates how to blink an LED connected to GPIO pin PA5 on the STM32F4 series microcontroller. The code enables the clock for GPIOA, configures PA5 as an output, and toggles the pin in an infinite loop with a delay.

# Hardware Requirements
- STM32F411RE Nucleo Board (or compatible STM32F4 series)
- On-board or external LED connected to pin PA5
# Software Requirements
- STM32CubeIDE (or any STM32 development environment)
- ARM GCC Compiler (included with STM32CubeIDE)
# How It Works
- The GPIOA peripheral clock is enabled.
- Pin PA5 is configured as an output.
- In the main loop, the pin is toggled on and off with a small delay between each toggle, causing the LED to blink.
# Code Explanation
- GPIOAEN: Enables the clock for GPIO port A.
- PIN5: Represents the 5th pin (PA5).
- LED_PIN: Defines the pin used to toggle the LED.
- MODER: Configures the mode for PA5 as output.
- ODR: Writes to the Output Data Register to toggle the LED.
# Usage 
- Compile and upload the code to the STM32 microcontroller.
- Observe the LED blinking on pin PA5.
