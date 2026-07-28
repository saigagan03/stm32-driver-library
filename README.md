# STM32F446 Register-Level Driver Library

## Overview

This project contains a register-level driver library developed from scratch for the STM32F446RE microcontroller.

The drivers are written directly using CMSIS register definitions without relying on STM32 HAL APIs for peripheral configuration.

The objective of this project is to gain a deep understanding of ARM Cortex-M architecture, STM32 peripherals, and embedded software development.

---

## Hardware

- STM32 NUCLEO-F446RE
- ARM Cortex-M4
- STM32CubeIDE
- CMSIS

---

## Drivers Implemented

### GPIO

- GPIO Output Driver
- GPIO Input Driver
- Pull-Up Configuration
- Pull-Down Configuration
- Pin Read
- Pin Write
- Pin Toggle

### Interrupts

- SYSCFG Configuration
- EXTI Configuration
- NVIC Configuration
- Falling Edge Trigger
- Rising Edge Trigger
- Both Edge Trigger
- Button Interrupt Project

---

## Features

- Register-level programming
- No HAL GPIO APIs used
- Modular driver architecture
- Easy to extend for additional peripherals

---

## Project Structure

```
Core/
    Inc/
        gpio_driver.h

    Src/
        gpio_driver.c

Drivers/

Startup/

```

---

## Current Progress

- [x] GPIO Driver
- [x] GPIO Input Driver
- [x] Pull-Up / Pull-Down
- [x] GPIO Interrupt Driver
- [x] EXTI Driver
- [ ] UART Driver
- [ ] Timer Driver
- [ ] PWM Driver
- [ ] ADC Driver
- [ ] SPI Driver
- [ ] I2C Driver

---

## Future Work

- UART Driver
- Timer Driver
- PWM
- ADC
- SPI
- I2C
- EEPROM Driver
- Watchdog Driver
- RTC Driver

---

## Development Approach

Every driver in this repository is developed incrementally:

- Theory
- Register Study
- Driver Implementation
- Practical Project
- Testing

---

## Author

Sai Gagan E

Electrical Engineering  
Maulana Azad National Institute of Technology (MANIT), Bhopal
