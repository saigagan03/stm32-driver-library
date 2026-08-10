# STM32F446 Register-Level Driver Library

## Overview

This project contains a **register-level embedded driver library developed from scratch for the STM32F446RE microcontroller**.

The drivers are implemented using **CMSIS register definitions** without relying on STM32 HAL APIs for peripheral configuration.

The main objective of this project is to develop a strong understanding of:

* ARM Cortex-M4 architecture
* STM32 peripheral registers
* Embedded C
* Peripheral initialization
* Interrupt handling
* Register-level driver development
* Hardware/software interaction

Each peripheral is developed incrementally through:

```text
Theory
   ↓
Register Study
   ↓
Driver Development
   ↓
Hardware Testing
   ↓
Practical Project
```

---

# Hardware & Software

* **Microcontroller:** STM32F446RE
* **Board:** STM32 NUCLEO-F446RE
* **Core:** ARM Cortex-M4
* **IDE:** STM32CubeIDE
* **Programming Language:** C
* **Register Definitions:** CMSIS
* **Debugger:** ST-LINK

---

# Drivers Implemented

## 1. GPIO Driver

The GPIO driver provides register-level control of STM32 GPIO peripherals.

### Features

* GPIO Output Driver
* GPIO Input Driver
* Pin Mode Configuration
* Pull-Up Configuration
* Pull-Down Configuration
* Pin Read
* Pin Write
* Pin Toggle
* Alternate Function Configuration
* GPIO Peripheral Clock Enable

---

# 2. External Interrupt Driver

External interrupt functionality was implemented using the STM32 interrupt architecture.

### Features

* SYSCFG configuration
* EXTI configuration
* NVIC configuration
* Rising-edge detection
* Falling-edge detection
* Both-edge detection
* External button interrupt handling

### Project Implemented

**GPIO Button Interrupt Project**

```text
Push Button
     ↓
   GPIO
     ↓
   EXTI
     ↓
   NVIC
     ↓
Interrupt Handler
     ↓
GPIO Response
```

The project was hardware-tested using the STM32F446RE.

---

# 3. UART Driver

A register-level UART driver was developed without using STM32 HAL peripheral APIs.

### Features

* UART peripheral initialization
* Register-level UART configuration
* Baud-rate configuration
* TX/RX configuration
* Polling-based communication
* Character transmission
* String transmission
* Character reception
* UART Echo functionality

### Implemented APIs

```c
UART_Init();

UART_SendChar();

UART_SendString();

UART_ReceiveChar();
```

---

# 4. UART Terminal Project

A polling-based UART terminal communication project was developed using the STM32F446RE.

### Features

* STM32 ↔ PC serial communication
* Character transmission
* String transmission
* Character reception
* UART echo
* Serial terminal testing

### Communication Flow

```text
       PC Terminal
            │
            │ Character
            ▼
     STM32 UART RX
            │
            ▼
     STM32 UART TX
            │
            │ Echo
            ▼
       PC Terminal
```

The UART communication was tested using a PC serial terminal.

---

# 5. Timer Driver

A register-level timer driver was developed for STM32 timers.

Currently tested with:

* TIM2
* TIM3

### Features

* Timer peripheral clock enable
* Prescaler configuration
* Auto-reload register configuration
* Counter reset
* Counter reading
* Timer start
* Timer stop
* Update interrupt configuration
* NVIC timer interrupt configuration

### Implemented APIs

```c
Timer_Init();

Timer_Start();

Timer_Stop();

Timer_ResetCounter();

Timer_GetCounter();

Timer_EnableUpdateInterrupt();
```

---

# 6. Timer-Based Delay Driver

A timer-based millisecond delay function was developed using the timer counter.

### Features

* Register-level timer delay
* Configurable timer prescaler
* Millisecond delay generation
* Reusable delay driver

### API

```c
Delay_ms();
```

A separate timer can be used for delay generation while another timer operates as a PWM generator.

---

# 7. Timer Interrupt Project

Periodic timer interrupts were implemented using:

* TIM2/TIM3
* Update interrupt
* DIER
* SR
* NVIC
* Timer interrupt handlers

### Concept

```text
Timer Counter
      ↓
     ARR
      ↓
Update Event
      ↓
     UIF
      ↓
    NVIC
      ↓
Interrupt Handler
```

The periodic interrupt functionality was hardware-tested.

---

# 8. PWM Driver

PWM functionality was implemented using the STM32 timer peripheral in **PWM Mode 1**.

### PWM Features

* PWM generation
* Prescaler configuration
* ARR configuration
* CCR configuration
* PWM Mode 1
* Output Compare preload
* Output channel enable
* Output polarity configuration
* Duty-cycle control
* PWM channel generalization

The driver was generalized to support:

```text
TIMx Channel 1
TIMx Channel 2
TIMx Channel 3
TIMx Channel 4
```

### PWM Duty Cycle

```text
Duty Cycle = HIGH Time / Total Period × 100
```

The compare register is updated according to the requested duty cycle.

### API

```c
Timer_PWM_Init();

Timer_PWM_Start();

Timer_PWM_Stop();

Timer_PWM_SetDuty();
```

---

# 9. LED PWM Brightness Control Project

PWM was applied to an LED to control its brightness.

### Working

```text
STM32 Timer
     ↓
    PWM
     ↓
Duty Cycle
     ↓
   LED
     ↓
Brightness
```

The duty cycle was gradually increased and decreased to create a smooth brightness variation.

The project was hardware-tested using the STM32F446RE.

---

# 10. Servo Motor Control Project

PWM was further applied to servo motor control.

Unlike simple LED brightness control, a servo requires a specific PWM **frequency and pulse width**.

The timer was configured for approximately:

```text
PWM Frequency = 50 Hz
PWM Period    = 20 ms
```

The servo angle was mapped to the pulse width:

```text
0°   → 1.0 ms
90°  → 1.5 ms
180° → 2.0 ms
```

### Servo Angle Mapping

```text
        Servo_SetAngle()
               │
               ▼
        Requested Angle
          0° → 180°
               │
               ▼
        Pulse Width
       1 ms → 2 ms
               │
               ▼
             CCR
               │
               ▼
             PWM
```

### API

```c
Servo_SetAngle();
```

The resulting `CCR` values were verified using the STM32 debugger.

A software sweep was also implemented:

```c
for(uint32_t angle = 0; angle <= 180; angle++)
{
    Servo_SetAngle(&htim2, angle);
    Delay_ms(&htim3, 10);
}

for(uint32_t angle = 180; angle > 0; angle--)
{
    Servo_SetAngle(&htim2, angle);
    Delay_ms(&htim3, 10);
}
```

---

# Current Phase Progress

## Phase 4 — Register-Level Driver Development

| Lesson | Topic                         | Status |
| -----: | ----------------------------- | :----: |
|      1 | Clock Tree                    |    ✅   |
|      2 | RCC Registers                 |    ✅   |
|      3 | Peripheral Clock Enable       |    ✅   |
|      4 | GPIO Driver Enhancement       |    ✅   |
|      5 | GPIO Input Driver             |    ✅   |
|      6 | GPIO Output Driver            |    ✅   |
|      7 | Pull-Up / Pull-Down           |    ✅   |
|      8 | GPIO Interrupt Pins           |    ✅   |
|      9 | External Interrupt Theory     |    ✅   |
|     10 | EXTI Registers                |    ✅   |
|     11 | Button Interrupt Project      |    ✅   |
|     12 | UART Theory                   |    ✅   |
|     13 | UART Registers                |    ✅   |
|     14 | UART Driver Development       |    ✅   |
|     15 | UART Terminal Project         |    ✅   |
|     16 | Timer Theory                  |    ✅   |
|     17 | Timer Registers               |    ✅   |
|     18 | Delay Functions               |    ✅   |
|     19 | Periodic Interrupt Project    |    ✅   |
|     20 | PWM Theory                    |    ✅   |
|     21 | PWM LED Brightness Project    |    ✅   |
|     22 | Servo Motor Control Project   |    ✅   |
|     23 | ADC Theory                    |   🔜   |
|     24 | ADC Registers                 |   🔜   |
|     25 | Potentiometer Reading Project |   🔜   |
|     26 | SPI Theory                    |   🔜   |
|     27 | SPI Registers                 |   🔜   |
|     28 | SPI Driver Development        |   🔜   |
|     29 | SPI Sensor Interface Project  |   🔜   |
|     30 | I²C Theory                    |   🔜   |
|     31 | I²C Registers                 |   🔜   |
|     32 | I²C Driver Development        |   🔜   |
|     33 | I²C EEPROM Project            |   🔜   |
|     34 | Watchdog Timer                |   🔜   |

---

# Completed Projects

### 1. GPIO Button Interrupt Project

Implemented:

* GPIO
* SYSCFG
* EXTI
* NVIC
* Interrupt handler

---

### 2. UART Terminal Project

Implemented:

* UART TX
* UART RX
* Character communication
* String communication
* Echo functionality

---

### 3. Timer Periodic Interrupt Project

Implemented:

* Timer configuration
* Update interrupts
* NVIC
* Periodic interrupt generation

---

### 4. PWM LED Brightness Project

Implemented:

* Timer PWM
* Duty-cycle control
* LED brightness control

---

### 5. Servo Motor Control Project

Implemented:

* 50 Hz PWM
* Pulse-width based angle control
* Generalized timer channel support
* Servo angle sweep

---

# Project Structure

```text
STM32F446_Register_Driver/
│
├── Core/
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
├── STM32F446RETX_FLASH.ld
│
└── README.md
```

---

# Development Philosophy

The project follows a **register-first approach**.

Instead of directly using high-level HAL APIs, each peripheral is understood and implemented from its hardware registers.

For every peripheral:

```text
1. Understand peripheral operation
           ↓
2. Study reference manual
           ↓
3. Identify required registers
           ↓
4. Understand individual bits
           ↓
5. Implement driver
           ↓
6. Test registers using debugger
           ↓
7. Build practical project
           ↓
8. Generalize driver
```

This approach is intended to build a strong foundation for embedded firmware development.

---

# Learning Outcomes

Through this project, the following skills are being developed:

* Embedded C programming
* ARM Cortex-M4 architecture
* STM32 peripheral architecture
* CMSIS register-level programming
* GPIO configuration
* Interrupt handling
* NVIC configuration
* UART communication
* Timer configuration
* Timer interrupts
* PWM generation
* Duty-cycle control
* Servo motor control
* Modular driver development
* Debugger-based register verification
* Hardware/software integration

---

# Upcoming Development

The next milestone is **ADC**.

Planned progression:

```text
ADC Theory
    ↓
ADC Registers
    ↓
ADC Driver
    ↓
Potentiometer Reading
    ↓
UART ADC Monitoring
```

Future peripherals:

```text
ADC
 ↓
SPI
 ↓
I²C
 ↓
EEPROM
 ↓
Watchdog
```

---

# Author

**Sai Gagan E**

B.Tech Electrical Engineering

**Maulana Azad National Institute of Technology (MANIT), Bhopal**

