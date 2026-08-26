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
```

A button press generates an external interrupt, which is handled by the NVIC and used to control a GPIO output.

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

### Implemented APIs

```c
void UART_SendChar(char data);

void UART_SendString(char *str);

char UART_ReceiveChar(void);
```

---

# UART Terminal Communication Project

A polling-based UART terminal project was developed using the STM32F446RE.

### Features

* STM32-to-PC UART communication
* Polling-based transmission and reception
* Character-by-character communication
* UART echo functionality
* Serial terminal testing

### Working

```text
PC Terminal
     |
     | Character
     v
STM32 UART Receiver
     |
     v
STM32 UART Transmitter
     |
     v
PC Terminal
```

Any character entered in the PC terminal is received by the STM32 and transmitted back to the terminal.

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

### Implemented APIs

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

# Timer Periodic Interrupt Project

A periodic timer interrupt project was developed using the STM32 timer peripheral.

### Features

* Timer initialization
* Prescaler configuration
* Auto-reload configuration
* Update interrupt generation
* NVIC configuration
* Periodic interrupt handling

This project demonstrates how a hardware timer can be used to generate periodic events without continuously polling the timer in software.

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

### Implemented APIs

```c
Timer_PWM_Init();

Timer_PWM_Start();

Timer_PWM_Stop();

Timer_PWM_SetDuty();
```

---

# PWM LED Brightness Project

PWM was used to control LED brightness by varying the duty cycle of the timer output.

The project implements a smooth brightness transition by gradually increasing and decreasing the PWM duty cycle.

```text
Timer
  |
  v
 PWM Generator
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

The timer was configured to generate a **50 Hz PWM signal** with a **20 ms period**.

### Servo Angle Mapping

```text
0°    → 1.0 ms pulse
90°   → 1.5 ms pulse
180°  → 2.0 ms pulse
```

### Implemented API

```c
Servo_SetAngle();
```

A software angle sweep from **0° to 180° and back** was also implemented.

The corresponding PWM compare values were verified using the STM32 debugger.

---

# ADC Driver

A generalized register-level **ADC driver** was implemented for the STM32F446RE.

The driver provides direct configuration and control of the STM32 ADC peripheral using CMSIS register definitions.

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

The driver is designed to provide a reusable foundation for analog sensor and potentiometer-based applications.

### ADC Conversion Flow

```text
Analog Input
     |
     v
ADC Channel
     |
     v
ADC Configuration
     |
     v
Start Conversion
     |
     v
Wait for EOC
     |
     v
Read ADC Data Register
     |
     v
Digital ADC Value
```

### Generalized Driver Approach

The ADC driver is designed around peripheral configuration rather than a single application, allowing the same driver to be extended for different analog-input projects.

---

# Current Driver Architecture

The project currently contains the following major peripheral drivers:

```text
                 STM32F446RE
                      |
        +-------------+-------------+
        |             |             |
       GPIO          UART          ADC
        |             |             |
        |             |             |
      EXTI          Terminal    Analog Input
        |
       NVIC
        |
      Timer
        |
   +----+----+
   |         |
  PWM      Delay
   |
   +---------+
   |         |
  LED      Servo
```

---

# Completed Projects

## 1. GPIO Interrupt Button Project

Implemented external interrupt handling using:

* SYSCFG
* EXTI
* NVIC

### Features

* Button press detection
* External interrupt generation
* Interrupt handler implementation
* GPIO response after interrupt event

---

## 2. UART Terminal Communication Project

Implemented UART communication using the polling method.

### Features

* Register-level UART initialization
* Character transmission
* String transmission
* Character reception
* UART echo application
* PC terminal communication

---

## 3. Timer Periodic Interrupt Project

Implemented periodic timer interrupts using the STM32 timer peripheral.

### Features

* Timer configuration
* Prescaler configuration
* Update interrupt
* NVIC configuration
* Periodic interrupt generation

---

## 4. PWM LED Brightness Project

Implemented PWM-based LED brightness control.

### Features

* PWM generation
* Duty-cycle control
* Smooth brightness variation
* Hardware testing

---

## 5. Servo Motor Control Project

Implemented servo angle control using timer PWM.

### Features

* 50 Hz PWM generation
* Pulse-width-based angle control
* 0°–180° angle mapping
* Software servo sweep
* Debugger-based CCR verification

---

## 6. ADC Driver

Implemented a generalized register-level ADC driver.

### Features

* ADC peripheral initialization
* ADC channel configuration
* Software-triggered conversion
* End-of-conversion handling
* ADC data register reading
* Polling-based conversion

The driver provides the foundation for future analog-input applications such as potentiometer and sensor interfacing.

---

# Current Progress

* [x] GPIO Driver
* [x] GPIO Input Driver
* [x] GPIO Output Driver
* [x] Pull-Up / Pull-Down Configuration
* [x] GPIO Alternate Function Configuration
* [x] GPIO Interrupt Driver
* [x] SYSCFG Configuration
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
* [x] ADC Driver
* [ ] ADC Application Project
* [ ] SPI Driver
* [ ] I2C Driver
* [ ] Watchdog Driver
* [ ] RTC Driver

---

# Future Work

The following drivers and applications are planned for future development:

## ADC Applications

* Potentiometer Reading Project
* Analog sensor interfacing
* ADC-based voltage measurement

## SPI

* SPI register-level driver
* SPI sensor interface project
* SPI communication testing

## I2C

* I2C register-level driver
* I2C EEPROM interface
* I2C sensor communication

## Other Peripherals

* Independent Watchdog Driver
* Window Watchdog Driver
* RTC Driver
* Additional timer-based applications

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
│   │   ├── delay.h
│   │   └── adc_driver.h
│   │
│   └── Src/
│       ├── gpio_driver.c
│       ├── uart_driver.c
│       ├── timer_driver.c
│       ├── delay.c
│       ├── adc_driver.c
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

# Development Approach

Every driver in this repository is developed incrementally using the following workflow:

```text
Theory Understanding
        ↓
Peripheral Reference Manual Study
        ↓
Register Analysis
        ↓
Driver Implementation
        ↓
Debugging
        ↓
Hardware Testing
        ↓
Practical Application
```

This approach focuses on understanding **what happens at the register and hardware level** instead of treating the peripheral as a black box.

---

# Design Philosophy

The project follows several principles:

### 1. Register-Level Understanding

Peripheral configuration is performed through direct register manipulation using CMSIS definitions.

### 2. Modular Drivers

Each peripheral is implemented as an independent driver so that it can be reused across different applications.

### 3. Generalization

Where possible, drivers are designed to support multiple peripherals, channels, pins, and configurations rather than being tied to a single application.

### 4. Hardware Validation

Drivers are tested on the actual STM32F446RE hardware wherever applicable.

### 5. Incremental Development

Each peripheral is developed from the underlying hardware theory and reference manual before being converted into reusable driver APIs.

---

# Key Features

* Register-level embedded programming
* Direct CMSIS register access
* No STM32 HAL peripheral APIs
* Modular driver architecture
* Generalized timer and PWM configuration
* GPIO interrupt support
* UART polling communication
* Timer interrupt handling
* PWM generation
* Servo control
* ADC conversion support
* Hardware-tested peripherals
* Reusable embedded driver APIs
* Practical peripheral-based projects

---

# Learning Outcomes

Through this project, the following concepts are being developed:

* ARM Cortex-M4 architecture
* STM32F4 peripheral architecture
* Memory-mapped peripheral registers
* GPIO configuration
* Interrupt architecture
* EXTI and NVIC
* UART communication
* Hardware timers
* Timer interrupts
* PWM generation
* Servo motor control
* ADC operation and conversion
* Embedded C programming
* Modular driver development
* Hardware debugging
* Peripheral abstraction without HAL dependency

---

# Roadmap

The current development roadmap is:

```text
GPIO
  ↓
Interrupts
  ↓
UART
  ↓
Timers
  ↓
PWM
  ↓
Servo
  ↓
ADC
  ↓
SPI
  ↓
I2C
  ↓
Watchdog
  ↓
RTC
```

The long-term objective is to build a comprehensive **register-level STM32F446 peripheral driver library** and use the drivers to develop increasingly complex embedded systems projects.

---

## Author

**Sai Gagan E**

B.Tech Electrical Engineering

**Maulana Azad National Institute of Technology (MANIT), Bhopal**
lets modify readme accordingly and give me the code

