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
* Communication protocols

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

A button press generates an external interrupt, which is handled by the NVIC and used to control a GPIO output.

UART Driver

A register-level UART driver was implemented without using STM32 HAL peripheral APIs.

Features
UART peripheral initialization
Register-level UART configuration
Baud-rate configuration
Polling-based communication
Character transmission
String transmission
Character reception
UART echo functionality
Implemented APIs
void UART_SendChar(char data);

void UART_SendString(char *str);

char UART_ReceiveChar(void);
UART Terminal Communication Project

A polling-based UART terminal project was developed using the STM32F446RE.

Features
STM32-to-PC UART communication
Polling-based transmission and reception
Character-by-character communication
UART echo functionality
Serial terminal testing
Working
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

Any character entered in the PC terminal is received by the STM32 and transmitted back to the terminal.

Timer Driver

A generalized register-level timer driver was developed and tested using TIM2 and TIM3.

Features
Timer peripheral clock configuration
Prescaler configuration
Auto-reload register configuration
Counter reset
Counter reading
Timer start/stop
Update event configuration
Update interrupt configuration
NVIC timer interrupt configuration
Timer-based delay generation
Implemented APIs
Timer_Init();

Timer_Start();

Timer_Stop();

Timer_ResetCounter();

Timer_GetCounter();

Timer_EnableUpdateInterrupt();

Delay_ms();
Timer Periodic Interrupt Project

A periodic timer interrupt project was developed using the STM32 timer peripheral.

Features
Timer initialization
Prescaler configuration
Auto-reload configuration
Update interrupt generation
NVIC configuration
Periodic interrupt handling

This project demonstrates how a hardware timer can be used to generate periodic events without continuously polling the timer in software.

PWM Driver

The timer driver was extended to support generalized PWM generation.

Features
PWM Mode 1
Duty-cycle control
ARR configuration
CCR configuration
Output Compare preload
Output channel enable
Output polarity configuration
PWM channels 1–4
Generalized GPIO Alternate Function configuration
Implemented APIs
Timer_PWM_Init();

Timer_PWM_Start();

Timer_PWM_Stop();

Timer_PWM_SetDuty();
PWM LED Brightness Project

PWM was used to control LED brightness by varying the duty cycle of the timer output.

The project implements a smooth brightness transition by gradually increasing and decreasing the PWM duty cycle.

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

The project was hardware-tested using the STM32F446RE.

Servo Motor Control Project

The PWM driver was further used to implement servo motor control.

The timer was configured to generate a 50 Hz PWM signal with a 20 ms period.

Servo Angle Mapping
0°    → 1.0 ms pulse
90°   → 1.5 ms pulse
180°  → 2.0 ms pulse
Implemented API
Servo_SetAngle();

A software angle sweep from 0° to 180° and back was also implemented.

The corresponding PWM compare values were verified using the STM32 debugger.

ADC Driver

A generalized register-level ADC driver was implemented for the STM32F446RE.

The driver provides direct configuration and control of the STM32 ADC peripheral using CMSIS register definitions.

Features
ADC peripheral clock configuration
ADC initialization
ADC enable/disable
ADC channel selection
ADC conversion start
End-of-conversion status checking
ADC data register reading
Software-triggered conversion
Polling-based ADC conversion

The driver is designed to provide a reusable foundation for analog sensor and potentiometer-based applications.

ADC Conversion Flow
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
Generalized Driver Approach

The ADC driver is designed around peripheral configuration rather than a single application, allowing the same driver to be extended for different analog-input projects.

SPI Driver

A generalized register-level SPI driver was implemented for the STM32F446RE.

The SPI driver directly configures the STM32 SPI peripheral through CMSIS register definitions without using STM32 HAL APIs.

The driver was designed to support SPI1, SPI2, and SPI3 using the same driver interface.

Features
SPI peripheral clock configuration
SPI1 support
SPI2 support
SPI3 support
GPIO Alternate Function configuration
Master mode configuration
Slave mode configuration
CPOL configuration
CPHA configuration
Baud-rate prescaler configuration
MSB-first configuration
LSB-first configuration
Hardware NSS configuration
Software NSS configuration
TXE flag handling
RXNE flag handling
BSY flag handling
Polling-based transmission
Polling-based reception
Full-duplex transmit/receive
Supported SPI Instances
SPI1
 ├── SCK  → PA5
 ├── MISO → PA6
 └── MOSI → PA7

SPI2
 ├── SCK  → PB13
 ├── MISO → PB14
 └── MOSI → PB15

SPI3
 ├── SCK  → PB3
 ├── MISO → PB4
 └── MOSI → PB5
Implemented APIs
void SPI_Init(SPI_Handle_t *hspi);

void SPI_Transmit(
    SPI_Handle_t *hspi,
    uint8_t *buffer,
    uint32_t length
);

uint8_t* SPI_Receive(
    SPI_Handle_t *hspi,
    uint8_t *buffer,
    uint32_t length
);

uint8_t* SPI_TransmitReceive(
    SPI_Handle_t *hspi,
    uint8_t *t_buffer,
    uint8_t *r_buffer,
    uint32_t length
);

uint8_t SPI_GetFlagStatus(
    SPI_Handle_t *hspi,
    uint8_t flag
);
SPI Configuration

The driver provides configurable:

                 SPI Configuration
                       |
        +--------------+--------------+
        |              |              |
      Mode           Clock          Frame
        |              |              |
   Master/Slave    CPOL / CPHA     Bit Order
                       |
                Baud Prescaler
                       |
                     NSS
SPI Transmission Flow
Application Buffer
       |
       v
     TXE ?
       |
       v
Write Data Register
       |
       v
SPI Peripheral
       |
       v
Serial Data Transmission
       |
       v
Wait for BSY = 0
SPI Receive Flow
Send Dummy Data
       |
       v
Generate SPI Clock
       |
       v
Receive Data
       |
       v
Check RXNE
       |
       v
Read Data Register
SPI Verification

The SPI driver was verified during development by inspecting the SPI peripheral registers using the STM32 debugger.

Important registers and flags verified during debugging include:

CR1
SR
DR
TXE
RXNE
BSY

The configuration was also tested with different SPI parameters including LSB-first bit ordering.

Current Driver Architecture

The project currently contains the following major peripheral drivers:

                         STM32F446RE
                              |
       +----------+-----------+-----------+----------+
       |          |           |           |          |
      GPIO       UART        ADC         SPI       Timer
       |          |           |           |          |
      EXTI     Terminal   Analog Input   SPI Bus    |
       |                                      +-----+-----+
      NVIC                                     |           |
       |                                      TX/RX       |
     Timer                                                |
       |                                                PWM
   +---+---+                                      +------+------+
   |       |                                      |             |
  PWM    Delay                                   LED          Servo
Completed Projects
1. GPIO Interrupt Button Project

Implemented external interrupt handling using:

SYSCFG
EXTI
NVIC
Features
Button press detection
External interrupt generation
Interrupt handler implementation
GPIO response after interrupt event
2. UART Terminal Communication Project

Implemented UART communication using the polling method.

Features
Register-level UART initialization
Character transmission
String transmission
Character reception
UART echo application
PC terminal communication
3. Timer Periodic Interrupt Project

Implemented periodic timer interrupts using the STM32 timer peripheral.

Features
Timer configuration
Prescaler configuration
Update interrupt
NVIC configuration
Periodic interrupt generation
4. PWM LED Brightness Project

Implemented PWM-based LED brightness control.

Features
PWM generation
Duty-cycle control
Smooth brightness variation
Hardware testing
5. Servo Motor Control Project

Implemented servo angle control using timer PWM.

Features
50 Hz PWM generation
Pulse-width-based angle control
0°–180° angle mapping
Software servo sweep
Debugger-based CCR verification
6. ADC Driver

Implemented a generalized register-level ADC driver.

Features
ADC peripheral initialization
ADC channel configuration
Software-triggered conversion
End-of-conversion handling
ADC data register reading
Polling-based conversion

The driver provides the foundation for future analog-input applications such as potentiometer and sensor interfacing.

7. SPI Driver

Implemented a generalized register-level SPI driver supporting SPI1, SPI2, and SPI3.

Features
SPI peripheral clock configuration
SPI1/SPI2/SPI3 support
GPIO Alternate Function configuration
Master/Slave configuration
CPOL/CPHA configuration
Baud-rate prescaler configuration
MSB/LSB-first configuration
Hardware/Software NSS configuration
Polling-based transmission
Polling-based reception
Full-duplex transmit/receive
SPI status flag handling
Register-level debugging
Current Progress
 GPIO Driver
 GPIO Input Driver
 GPIO Output Driver
 Pull-Up / Pull-Down Configuration
 GPIO Alternate Function Configuration
 GPIO Interrupt Driver
 SYSCFG Configuration
 EXTI Driver
 NVIC Configuration
 UART Driver
 UART Polling-Based Terminal Project
 Timer Driver
 Timer-Based Delay
 Timer Periodic Interrupt Project
 PWM Driver
 PWM LED Brightness Project
 Servo Motor Control Project
 ADC Driver
 ADC Application Project
 SPI Driver
 SPI1 Support
 SPI2 Support
 SPI3 Support
 SPI Transmit
 SPI Receive
 SPI Transmit/Receive
 SPI Register Verification
 SPI Sensor Interface Project
 I2C Driver
 I2C EEPROM Project
 Watchdog Driver
 RTC Driver
Future Work

The following drivers and applications are planned for future development.

ADC Applications
Potentiometer Reading Project
Analog sensor interfacing
ADC-based voltage measurement
SPI Applications
SPI sensor interface
SPI communication testing
External SPI peripheral integration
I2C
I2C register-level driver
I2C EEPROM interface
I2C sensor communication
Other Peripherals
Independent Watchdog Driver
Window Watchdog Driver
RTC Driver
Additional timer-based applications
Project Structure
STM32F446_Register_Driver/

│
├── Core/
│   │
│   ├── Inc/
│   │   ├── gpio_driver.h
│   │   ├── uart_driver.h
│   │   ├── timer_driver.h
│   │   ├── delay.h
│   │   ├── adc_driver.h
│   │   └── spi_driver.h
│   │
│   └── Src/
│       ├── gpio_driver.c
│       ├── uart_driver.c
│       ├── timer_driver.c
│       ├── delay.c
│       ├── adc_driver.c
│       ├── spi_driver.c
│       ├── main.c
│       └── stm32f4xx_it.c
│
├── Drivers/
│
├── Startup/
│
└── README.md
Development Approach

Every driver in this repository is developed incrementally using the following workflow:

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

This approach focuses on understanding what happens at the register and hardware level instead of treating the peripheral as a black box.

Design Philosophy

The project follows several principles.

1. Register-Level Understanding

Peripheral configuration is performed through direct register manipulation using CMSIS definitions.

2. Modular Drivers

Each peripheral is implemented as an independent driver so that it can be reused across different applications.

3. Generalization

Where possible, drivers are designed to support multiple peripherals, channels, pins, and configurations rather than being tied to a single application.

4. Hardware Validation

Drivers are tested on the actual STM32F446RE hardware wherever applicable.

5. Incremental Development

Each peripheral is developed from the underlying hardware theory and reference manual before being converted into reusable driver APIs.

6. Debugger-Based Verification

Peripheral registers and status flags are inspected during development to verify that the expected hardware configuration is actually taking place.

Key Features
Register-level embedded programming
Direct CMSIS register access
No STM32 HAL peripheral APIs
Modular driver architecture
Generalized GPIO configuration
Generalized timer and PWM configuration
GPIO interrupt support
UART polling communication
Timer interrupt handling
PWM generation
Servo control
ADC conversion support
SPI1/SPI2/SPI3 support
SPI polling-based communication
Full-duplex SPI communication
Hardware-tested peripherals
Register-level debugging
Reusable embedded driver APIs
Practical peripheral-based projects
Learning Outcomes

Through this project, the following concepts are being developed:

ARM Cortex-M4 architecture
STM32F4 peripheral architecture
Memory-mapped peripheral registers
GPIO configuration
Alternate Function configuration
Interrupt architecture
EXTI and NVIC
UART communication
Hardware timers
Timer interrupts
PWM generation
Servo motor control
ADC operation and conversion
SPI communication
SPI clock polarity and phase
SPI baud-rate configuration
SPI frame format
SPI status flags
Embedded C programming
Modular driver development
Hardware debugging
Peripheral abstraction without HAL dependency
Roadmap

The current peripheral development roadmap is:

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

The long-term objective is to build a comprehensive register-level STM32F446 peripheral driver library and use the drivers to develop increasingly complex embedded systems projects.

Next Development Stage

After completing the SPI driver, the next major stage is I2C driver development.

The planned sequence is:

SPI Driver
    ↓
SPI Application / Sensor Interface
    ↓
I2C Theory
    ↓
I2C Registers
    ↓
I2C Driver
    ↓
I2C EEPROM Project
    ↓
Watchdog
    ↓
RTC

After completing the major Phase 4 peripherals, the focus will move toward strengthening:

Advanced Embedded C
Communication protocols
Git and GitHub workflow
Linux
GCC
GDB
Debugging
Embedded interview preparation
Resume and portfolio development
Internship applications
Author

Sai Gagan E

B.Tech Electrical Engineering

Maulana Azad National Institute of Technology (MANIT), Bhopal


