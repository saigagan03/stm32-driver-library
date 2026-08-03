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

# Drivers Implemented

## GPIO Driver

Features:

- GPIO Output Driver
- GPIO Input Driver
- Pin Mode Configuration
- Pull-Up Configuration
- Pull-Down Configuration
- Pin Read
- Pin Write
- Pin Toggle

---

## Interrupt Driver

Features:

- SYSCFG Configuration
- EXTI Configuration
- NVIC Configuration
- Falling Edge Trigger
- Rising Edge Trigger
- Both Edge Trigger
- External Button Interrupt Handling

### Project Implemented:

**GPIO Button Interrupt Project**

- Configured external interrupt using EXTI
- Handled button press event through NVIC
- Tested interrupt functionality using GPIO output

---

## UART Driver

Implemented a register-level UART driver without using STM32 HAL APIs.

Features:

- UART peripheral initialization
- Register-level UART configuration
- Polling-based communication
- Character transmission
- String transmission
- Character reception
- UART Echo functionality

Implemented APIs:

```c
void UART_SendChar(char data);

void UART_SendString(char *str);

char UART_ReceiveChar(void);
```

---

# UART Terminal Project

A polling-based UART terminal communication project was developed using the STM32F446RE.

## Features

- STM32 communicates with PC terminal through UART
- Data transmission without interrupts
- Character-by-character communication
- Received characters are echoed back to terminal

## Implemented Functions

### UART Send Character

```c
UART_SendChar()
```

Used for transmitting a single character through UART.

---

### UART Send String

```c
UART_SendString()
```

Used for transmitting complete strings through UART terminal.

Example:

```
Hello STM32
```

---

### UART Receive Character

```c
UART_ReceiveChar()
```

Used for receiving characters from the PC terminal.

---

### UART Echo Project

Working:

```
PC Terminal
     |
     |  Character
     |
     v
 STM32 UART Receiver
     |
     |
     v
 STM32 UART Transmitter
     |
     |
     v
PC Terminal
```

Any character entered in the serial terminal is received by STM32 and transmitted back using UART.

---

# Features

- Register-level programming
- No STM32 HAL peripheral APIs used
- Direct CMSIS register access
- Modular driver architecture
- Hardware-tested drivers
- Easy extension for additional peripherals

---

# Project Structure

```
STM32F446_Register_Driver/

│
├── Core/
│   │
│   ├── Inc/
│   │   ├── gpio_driver.h
│   │   └── uart_driver.h
│   │
│   └── Src/
│       ├── gpio_driver.c
│       └── uart_driver.c
│
├── Drivers/
│
├── Startup/
│
└── README.md
```

---

# Completed Projects

## 1. GPIO Interrupt Button Project

Implemented external interrupt handling using:

- SYSCFG
- EXTI
- NVIC

Features:

- Button press detection
- Interrupt triggering
- GPIO response after interrupt event

---

## 2. UART Terminal Communication Project

Implemented UART communication using polling method.

Features:

- UART initialization from registers
- Send character function
- Send string function
- Receive character function
- Echo application

Communication tested using serial terminal.

---

# Current Progress

- [x] GPIO Driver
- [x] GPIO Input Driver
- [x] Pull-Up / Pull-Down Configuration
- [x] GPIO Interrupt Driver
- [x] EXTI Driver
- [x] NVIC Configuration
- [x] UART Driver
- [x] UART Polling-Based Terminal Project
- [ ] Timer Driver
- [ ] PWM Driver
- [ ] ADC Driver
- [ ] SPI Driver
- [ ] I2C Driver

---

# Future Work

Planned drivers:

- Timer Driver
- PWM Driver
- ADC Driver
- SPI Driver
- I2C Driver
- EEPROM Driver
- Watchdog Driver
- RTC Driver

---

# Development Approach

Every driver in this repository is developed incrementally:

1. Theory Understanding
2. Register Study
3. Driver Implementation
4. Hardware Testing
5. Practical Application Project

---

# Learning Outcomes

Through this project:

- Understanding ARM Cortex-M4 architecture
- Learning STM32 peripheral registers
- Writing reusable embedded drivers
- Understanding hardware abstraction layers
- Developing embedded firmware without HAL dependency

---

## Author

**Sai Gagan E**

B.Tech Electrical Engineering

MANIT Bhopal
