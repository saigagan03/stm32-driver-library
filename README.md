# STM32F446 Register-Level Driver Library

## Overview

This project contains a modular register-level driver library developed from scratch for the **STM32F446RE** microcontroller.

The drivers are implemented using **CMSIS register definitions** with direct access to STM32 peripheral registers, without relying on STM32 HAL APIs for peripheral configuration.

The primary objective of this project is to develop a strong understanding of:

* ARM Cortex-M4 architecture
* STM32 peripheral registers
* Embedded C programming
* Peripheral initialization and configuration
* Interrupt handling
* Hardware abstraction and driver design
* Hardware-level debugging and testing

Each driver is developed incrementally through theory, register analysis, implementation, debugging, and hardware testing.

---

# Hardware & Development Environment

* **Microcontroller:** STM32F446RE
* **Development Board:** STM32 NUCLEO-F446RE
* **Core:** ARM Cortex-M4
* **IDE:** STM32CubeIDE
* **Low-Level Framework:** CMSIS
* **Debugging:** ST-LINK
* **Language:** Embedded C

---

# Drivers Implemented

## GPIO Driver

A register-level GPIO driver was developed for configuring and controlling STM32 GPIO peripherals.

### Features

* GPIO output configuration
* GPIO input configuration
* Pin mode configuration
* Pull-up configuration
* Pull-down configuration
* Pin read
* Pin write
* Pin toggle
* Alternate Function configuration
* GPIO peripheral clock configuration

---

# Interrupt Driver

An external interrupt driver was implemented using the STM32 interrupt architecture.

### Features

* SYSCFG configuration
* EXTI configuration
* NVIC configuration
* Rising-edge trigger
* Falling-edge trigger
* Both-edge trigger
* External button interrupt handling

---

# UART Driver

A register-level UART driver was implemented without using STM32 HAL peripheral APIs.

### Features

* UART peripheral initialization
* Register-level UART configuration
* Baud-rate configuration
* Polling-based communication
* Character transmission
* String transmission
* Character reception
* UART echo functionality

---

# Timer Driver

A generalized register-level timer driver was developed and tested using **TIM2 and TIM3**.

### Features

* Timer peripheral clock configuration
* Prescaler configuration
* Auto-reload register configuration
* Counter reset
* Counter reading
* Timer start/stop
* Update event configuration
* Update interrupt configuration
* NVIC timer interrupt configuration
* Timer-based delay generation

---

# PWM Driver

The timer driver was extended to support generalized PWM generation.

### Features

* PWM Mode 1
* Duty-cycle control
* ARR configuration
* CCR configuration
* Output Compare preload
* Output channel enable
* Output polarity configuration
* PWM channels 1–4
* Generalized GPIO Alternate Function configuration

---

# ADC Driver

A generalized register-level **ADC driver** was implemented for the STM32F446RE.

### Features

* ADC peripheral clock configuration
* ADC initialization
* ADC enable/disable
* ADC channel selection
* ADC conversion start
* End-of-conversion status checking
* ADC data register reading
* Software-triggered conversion
* Polling-based ADC conversion

---

# SPI Driver

A generalized register-level **SPI driver** was implemented supporting **SPI1, SPI2, and SPI3**.

The driver provides direct configuration and control of the STM32 SPI peripheral using CMSIS register definitions.

### Features

* SPI peripheral clock configuration (APB1/APB2)
* SPI1/SPI2/SPI3 support with GPIO AF configuration
* Master/Slave mode configuration
* CPOL and CPHA configuration (Mode 0-3)
* Baud-rate prescaler configuration (DIV2 to DIV256)
* MSB/LSB first configuration
* Hardware and Software NSS management (SSM + SSI to avoid MODF)
* 8-bit Data Frame Format
* TXE, RXNE, BSY flag handling
* Overrun handling (RXNE clear via DR read)

### Implemented APIs

```c
void SPI_Init(SPI_Handle_t *hspi);
void SPI_Transmit(SPI_Handle_t *hspi, uint8_t *buffer, uint32_t length);
uint8_t* SPI_Receive(SPI_Handle_t *hspi, uint8_t *buffer, uint32_t length);
uint8_t* SPI_TransmitReceive(SPI_Handle_t* hspi, uint8_t *t_buffer, uint8_t* r_buffer, uint32_t length);
uint8_t SPI_GetFlagStatus(SPI_Handle_t* hspi, uint8_t flag);

