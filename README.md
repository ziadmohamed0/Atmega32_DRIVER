<h2>Eng : Ziad Mohammed Fathi </h2>

# ATmega32 Drivers Repository

This repository contains a comprehensive suite of drivers for the ATmega32 microcontroller, designed to facilitate the development of embedded systems projects. The drivers are organized into several folders, each serving a specific purpose within the system.

## Folder Structure

- **Hall**: This folder contains higher abstraction layer drivers.
  - `LCD`: Driver for interfacing with LCD displays.
  - `BCD`: Driver for interfacing with 7-Segment displays.
  - `KEYPAD`: Driver for matrix keypad interfacing.
  - `L298_DC_MOTOR`: Driver for controlling DC motors.
  - `RELAY`: Driver for controlling RELAY.

- **Mcal**: Microcontroller abstraction layer drivers.
  - `ADC`: Analog-to-digital converter driver.
  - `DIO`: Digital Input/Output driver.
  - `INTERRUPT`: External interrupt handling driver.
  - `TIMER0`: Timer0 handling driver.
  - `TIMER1`: Timer1 handling driver.
  - `TIMER2`: Timer2 handling driver.
  - `SPI` : SPI handling driver.
  - `I2C` : I2C handling driver.
  - `UART`: UART handling driver.

- **Serv**: Service layer with common utilities and data types.
  - `BIT_Math`: Bit manipulation macros.
  - `STD_Types`: Standard data type definitions.
  - `Includes`: Common includes and configurations.

- **App**: Application layer where the main application code resides.

## Getting Started

To use these drivers in your project, clone this repository and include the desired drivers in your project's source directory.

```bash
git clone https://github.com/yourusername/atmega32-drivers.git

