# STM32F446 Register-Level Driver Library

## Overview

This project contains a register-level driver library developed from scratch for the STM32F446RE microcontroller.

The drivers are written directly using CMSIS register definitions without relying on STM32 HAL APIs for peripheral configuration.

The objective of this project is to gain a deep understanding of ARM Cortex-M architecture, STM32 peripherals, and embedded software development.

---

## Hardware

* STM32 NUCLEO-F446RE
* ARM Cortex-M4
* STM32CubeIDE
* CMSIS

---

# Drivers Implemented

## GPIO Driver

Features:

* GPIO Output Driver
* GPIO Input Driver
* Pin Mode Configuration
* Pull-Up Configuration
* Pull-Down Configuration
* Pin Read
* Pin Write
* Pin Toggle
* Alternate Function Configuration

---

## Interrupt Driver

Features:

* SYSCFG Configuration
* EXTI Configuration
* NVIC Configuration
* Falling Edge Trigger
* Rising Edge Trigger
* Both Edge Trigger
* External Button Interrupt Handling

### Project Implemented:

**GPIO Button Interrupt Project**

* Configured external interrupt using EXTI
* Handled button press event through NVIC
* Tested interrupt functionality using GPIO output

---

## UART Driver

Implemented a register-level UART driver without using STM32 HAL APIs.

Features:

* UART peripheral initialization
* Register-level UART configuration
* Polling-based communication
* Character transmission
* String transmission
* Character reception
* UART Echo functionality

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

* STM32 communicates with PC terminal through UART
* Data transmission without interrupts
* Character-by-character communication
* Received characters are echoed back to terminal

## Implemented Functions

### UART Send Character

```c
UART_SendChar()
```

Used for transmitting a single character through UART terminal.

---

### UART Send String

```c
UART_SendString()
```

Used for transmitting complete strings through UART terminal.

Example:

```text
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

```text
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

# Timer Driver

A register-level timer driver was developed and tested using TIM2 and TIM3.

Features:

* Timer peripheral clock enable
* Prescaler configuration
* Period/ARR configuration
* Counter reset
* Counter reading
* Timer start/stop
* Update interrupt configuration
* NVIC timer interrupt configuration
* Timer-based delay generation

Implemented APIs:

```c
Timer_Init();

Timer_Start();

Timer_Stop();

Timer_ResetCounter();

Timer_GetCounter();

Timer_EnableUpdateInterrupt();

Delay_ms();
```

---

# PWM Driver

The timer driver was extended to support PWM generation.

Features:

* PWM Mode 1
* Duty-cycle control
* ARR configuration
* CCR configuration
* Output Compare preload
* Output channel enable
* Output polarity configuration
* PWM channels 1–4
* Generalized GPIO Alternate Function configuration

Implemented APIs:

```c
Timer_PWM_Init();

Timer_PWM_Start();

Timer_PWM_Stop();

Timer_PWM_SetDuty();
```

---

# PWM LED Brightness Project

PWM was used to control LED brightness by varying the duty cycle.

The project implements a smooth brightness transition by gradually increasing and decreasing the PWM duty cycle.

```text
Timer
  |
  v
 PWM
  |
  v
Duty Cycle
  |
  v
 LED Brightness
```

The project was hardware-tested using the STM32F446RE.

---

# Servo Motor Control Project

The PWM driver was further used to implement servo motor control.

The timer was configured for a 50 Hz PWM signal with a 20 ms period.

Servo angle was mapped to pulse width:

```text
0°   → 1.0 ms
90°  → 1.5 ms
180° → 2.0 ms
```

Implemented API:

```c
Servo_SetAngle();
```

A software angle sweep from 0° to 180° and back was also implemented.

The corresponding CCR values were verified using the STM32 debugger.

---

# Features

* Register-level programming
* No STM32 HAL peripheral APIs used
* Direct CMSIS register access
* Modular driver architecture
* Hardware-tested drivers
* Timer and PWM channel generalization
* Easy extension for additional peripherals

---

# Project Structure

```text
STM32F446_Register_Driver/

│
├── Core/
│   │
│   ├── Inc/
│   │   ├── gpio_driver.h
│   │   ├── uart_driver.h
│   │   ├── timer_driver.h
│   │   └── delay.h
│   │
│   └── Src/
│       ├── gpio_driver.c
│       ├── uart_driver.c
│       ├── timer_driver.c
│       ├── delay.c
│       ├── main.c
│       └── stm32f4xx_it.c
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

* SYSCFG
* EXTI
* NVIC

Features:

* Button press detection
* Interrupt triggering
* GPIO response after interrupt event

---

## 2. UART Terminal Communication Project

Implemented UART communication using polling method.

Features:

* UART initialization from registers
* Send character function
* Send string function
* Receive character function
* Echo application

Communication tested using serial terminal.

---

## 3. Timer Periodic Interrupt Project

Implemented periodic timer interrupts using the STM32 timer peripheral.

Features:

* Timer configuration
* Update interrupt
* NVIC configuration
* Periodic interrupt generation

---

## 4. PWM LED Brightness Project

Implemented PWM-based LED brightness control.

Features:

* PWM generation
* Duty-cycle control
* Smooth brightness variation

---

## 5. Servo Motor Control Project

Implemented servo angle control using timer PWM.

Features:

* 50 Hz PWM generation
* Pulse-width based angle control
* 0°–180° angle mapping
* Software servo sweep

---

# Current Progress

* [x] GPIO Driver
* [x] GPIO Input Driver
* [x] Pull-Up / Pull-Down Configuration
* [x] GPIO Interrupt Driver
* [x] EXTI Driver
* [x] NVIC Configuration
* [x] UART Driver
* [x] UART Polling-Based Terminal Project
* [x] Timer Driver
* [x] Timer-Based Delay
* [x] Timer Periodic Interrupt Project
* [x] PWM Driver
* [x] PWM LED Brightness Project
* [x] Servo Motor Control Project
* [ ] ADC Driver
* [ ] SPI Driver
* [ ] I2C Driver

---

# Future Work

Planned drivers and projects:

* ADC Driver
* Potentiometer Reading Project
* SPI Driver
* SPI Sensor Interface Project
* I2C Driver
* I2C EEPROM Project
* Watchdog Driver
* RTC Driver

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

* Understanding ARM Cortex-M4 architecture
* Learning STM32 peripheral registers
* Writing reusable embedded drivers
* Understanding hardware abstraction layers
* Developing embedded firmware without HAL dependency

---

## Author

**Sai Gagan E**

B.Tech Electrical Engineering

MANIT Bhopal
