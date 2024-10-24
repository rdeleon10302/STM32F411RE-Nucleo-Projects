# Continuous ADC Conversion on STM32

This project demonstrates how to set up the ADC (Analog-to-Digital Converter) on an STM32 microcontroller for continuous conversion. The STM32 ADC is configured to read an analog signal continuously, which can be useful in applications such as sensor monitoring or data acquisition systems where you need real-time analog input.

## Overview

In this project, we will:
- Configure the ADC to continuously sample an analog input.
- Read and store the converted digital values from the ADC Data Register.
- Enable continuous mode to ensure the ADC keeps converting without additional triggers.

### Key Concepts:
- Continuous ADC conversion mode.
- Reading data from the ADC Data Register.
- Basic real-time data acquisition.

## Project Setup

1. **Enable Clock for the ADC**: The clock for the ADC peripheral must be enabled in the RCC.
2. **Configure the GPIO Pin for Analog Input**: Set the corresponding GPIO pin (e.g., PA0) to analog mode for ADC input.
3. **Configure the ADC**: Set up the ADC to work in continuous conversion mode.
4. **Start the ADC**: Begin the continuous conversion process, and the ADC will automatically keep converting the analog input.
5. **Read ADC Data**: Continuously monitor the ADC Data Register (DR) to retrieve the converted digital values.

## Code Breakdown

### 1. Clock Configuration:
- The clock for both the ADC peripheral and the GPIO port used for the analog pin is enabled.

### 2. GPIO Configuration:
- The GPIO pin connected to the analog input (e.g., PA0) is configured in analog mode by modifying the appropriate GPIO registers.

### 3. ADC Configuration:
- The ADC is set to continuous conversion mode. This is done by configuring the ADC's **CR2** register, enabling the continuous mode bit and turning on the ADC.
- A single channel (e.g., channel 0 for PA0) is selected for conversion in the **SQR3** register.
  
### 4. ADC Conversion:
- The ADC is started, and continuous conversion begins.
- Converted values are read from the **ADC->DR** (Data Register) after each conversion.

## Requirements

- **Hardware**: STM32F4 (or compatible) board, potentiometer or any other analog input source.
- **Software**: STM32CubeIDE, Keil uVision, or any other STM32 development environment.

## How to Run

1. Connect an analog signal (e.g., a potentiometer or sensor) to the appropriate analog input pin (e.g., PA0).
2. Open the project in your preferred STM32 IDE.
3. Compile and flash the code to your STM32 board.
4. Monitor the ADC values either using a debugger or sending them to a UART for display on a terminal.
   
## Notes

- **Resolution**: By default, the STM32 ADC operates at 12-bit resolution, meaning the converted values range from 0 to 4095. This can be scaled depending on the reference voltage.
- **Sampling Time**: Ensure the ADC sampling time is configured appropriately for the speed of the analog signal being read.

### Example Application

This continuous ADC setup can be used in:
- Temperature monitoring systems.
- Light intensity sensing.
- Any system requiring real-time analog input conversion.

## License

This project is open-source and free to use for educational purposes. Feel free to modify and adapt it for your own projects.
