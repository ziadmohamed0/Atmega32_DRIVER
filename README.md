<h1>Driver Atmega32 .</h1>
<h3>Eng : Ziad Mohammed Fathi </h3>


# ATmega32 Drivers Repository

This repository contains a comprehensive suite of drivers for the ATmega32 microcontroller, designed to facilitate the development of embedded systems projects. The drivers are organized into several folders, each serving a specific purpose within the system.

## Folder Structure

- **Hall**: This folder contains higher abstraction layer drivers.
  - `lcd`: Driver for interfacing with LCD displays.
  - `bcd`: Driver for interfacing with 7-Segment displays.
  - `ultrasonic sensor`: Driver for ultrasonic distance measurement.
  - `keypad`: Driver for matrix keypad interfacing.
  - `dc_Motor`: Driver for controlling DC motors.
  - `Initialize`: Driver for Connects all interfaces together.

- **Mcal**: Microcontroller abstraction layer drivers.
  - `ADC`: Analog-to-digital converter driver.
  - `DIO`: Digital Input/Output driver.
  - `EX_Interrupt`: External interrupt handling driver.

- **Serv**: Service layer with common utilities and data types.
  - `BIT_Math`: Bit manipulation macros.
  - `STD_Types`: Standard data type definitions.
  - `Includes`: Common includes and configurations.

- **App**: Application layer where the main application code resides.

## Getting Started

To use these drivers in your project, clone this repository and include the desired drivers in your project's source directory.

```bash
git clone https://github.com/yourusername/atmega32-drivers.git

