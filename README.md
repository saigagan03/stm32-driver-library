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
* Communication protocols
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

### Project Implemented

**GPIO Button Interrupt Project**

The project demonstrates external interrupt handling using:

```text
GPIO Input
    |
    v
  SYSCFG
    |
    v
   EXTI
    |
    v
   NVIC
    |
    v
Interrupt Handler
    |
    v
GPIO Output


