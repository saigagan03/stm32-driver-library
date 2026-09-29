# STM32F446 Register-Level Driver Library

A modular **register-level peripheral driver library** developed from scratch for the **STM32F446RE** microcontroller using Embedded C and CMSIS.

The project focuses on understanding STM32 peripherals at the **register and hardware level**, without using STM32 HAL APIs for peripheral configuration.

The drivers are implemented, debugged, and progressively validated on a **NUCLEO-F446RE development board** using real hardware and a USB logic analyzer where applicable.

---

## Project Overview

The objective of this project is to build a reusable STM32 peripheral driver library while developing a strong understanding of:

- ARM Cortex-M4 architecture
- STM32F4 peripheral architecture
- Memory-mapped peripheral registers
- Embedded C
- GPIO configuration
- Interrupt architecture
- EXTI and NVIC
- UART communication
- Hardware timers
- PWM generation
- ADC conversion
- SPI communication
- I2C communication
- EEPROM interfacing
- Hardware debugging and verification
- Modular driver design

The development workflow followed throughout the project is:

Hardware & Development Environment
Component	Details
Microcontroller	STM32F446RE
Development Board	NUCLEO-F446RE
CPU Core	ARM Cortex-M4
Programming Language	Embedded C
IDE	STM32CubeIDE
Low-Level Framework	CMSIS
Debugger/Programmer	ST-LINK
Logic Analyzer	8-channel USB logic analyzer
Waveform Software	PulseView
Version Control	Git / GitHub

Register-Level Approach

The drivers use CMSIS peripheral definitions and direct register manipulation.

Example:

RCC->AHB1ENR |= (1 << 0);
GPIOA->MODER |= (1 << 10);
GPIOA->ODR ^= (1 << 5);

The project does not depend on STM32 HAL peripheral APIs for configuring the implemented drivers.

This provides practical experience with:

Clock enable registers
GPIO mode registers
GPIO output/input registers
Alternate function registers
Peripheral control/status registers
Interrupt enable registers
Timer registers
ADC registers
SPI registers
I2C registers
Peripheral Theory
       ↓
Reference Manual Study
       ↓
Register Analysis
       ↓
Driver Implementation
       ↓
Debugging
       ↓
Hardware Verification
       ↓
Application Development
