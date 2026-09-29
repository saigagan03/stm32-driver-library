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
- Hardware debugging and verification
- Modular driver design

The development workflow followed throughout the project is:

```text
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

For example:

RCC->AHB1ENR |= (1 << 0);
GPIOA->MODER |= (1 << 10);
GPIOA->ODR ^= (1 << 5);

The project does not depend on STM32 HAL peripheral APIs for configuring the implemented drivers.

This provides practical experience with:

Clock enable registers
GPIO mode registers
Alternate function registers
Peripheral control/status registers
Interrupt enable registers
Timer registers
ADC registers
SPI registers
I2C registers
Implemented Drivers
Driver	Status	Hardware Verification
GPIO	Implemented	Verified
EXTI / Interrupt	Implemented	Verified
UART	Implemented	Verified
Timer	Implemented	Verified
PWM	Implemented	Verified
Servo Control	Implemented	Application tested
ADC	Implemented	Verified
SPI	Implemented	Verified
I2C	Implemented	Verification pending
EEPROM	Implemented	Verification pending
GPIO Driver

A register-level GPIO driver was developed for configuring and controlling STM32 GPIO peripherals.

Features
GPIO input configuration
GPIO output configuration
Pin mode configuration
Pull-up configuration
Pull-down configuration
Pin read
Pin write
Pin toggle
Alternate Function configuration
GPIO peripheral clock configuration
Analog mode configuration
Hardware Verification

GPIO output operation was verified using PA5, which is connected to the onboard user LED on the NUCLEO-F446RE.

The PA5 output waveform was captured using the USB logic analyzer.

Evidence

GPIO PA5 waveform

EXTI / Interrupt Driver

A register-level external interrupt driver was implemented using the STM32 interrupt architecture.

Features
SYSCFG configuration
EXTI configuration
NVIC configuration
Rising-edge trigger
Falling-edge trigger
Both-edge trigger
External button interrupt handling
Test Configuration

The onboard B1 user button (PC13) was configured as an external interrupt source.

The interrupt handler toggles PA5 whenever the button interrupt occurs.

B1 Button
   |
  PC13
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
  PA5
Hardware Verification

The interrupt response was captured using the logic analyzer.

A hardware demonstration video is also included.

Evidence

EXTI button interrupt verification

UART Driver

A register-level UART driver was implemented without using STM32 HAL peripheral APIs.

Features
UART peripheral initialization
Baud-rate configuration
Polling-based communication
Character transmission
String transmission
Character reception
UART echo functionality
Example API
void UART_SendChar(UART_Handle_t *huart, char ch);

void UART_SendString(UART_Handle_t *huart, const char *str);
Test Configuration

USART2 was configured for:

Baud Rate : 115200
Data      : 8 bits
Parity    : None
Stop Bits : 1
Mode      : TX/RX

USART2 TX uses PA2 / Arduino D1 on the NUCLEO-F446RE.

Hardware Verification

UART communication was verified using a PC serial terminal.

Evidence

UART terminal verification

Timer Driver

A generalized register-level timer driver was developed using STM32 timers.

The driver was tested using TIM2 and TIM3.

Features
Timer peripheral clock configuration
Prescaler configuration
Auto-reload configuration
Counter reset
Counter reading
Timer start/stop
Update event configuration
Update interrupt configuration
NVIC timer interrupt configuration
Timer-based delay generation
Example APIs
Timer_Init();

Timer_Start();

Timer_Stop();

Timer_ResetCounter();

Timer_GetCounter();

Timer_EnableUpdateInterrupt();
Timer Periodic Interrupt Project

A periodic interrupt application was implemented using TIM2.

The timer was configured to generate a periodic update interrupt, and the interrupt handler toggles PA5.

For the verification setup:

Timer Clock = 84 MHz
Prescaler   = 8399
ARR         = 9999

This produces a timer update approximately every:

1 second
Hardware Verification

The resulting PA5 waveform was captured using the logic analyzer.

Evidence

Timer periodic interrupt waveform

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
Example APIs
Timer_PWM_Init();

Timer_PWM_Start();

Timer_PWM_Stop();

Timer_PWM_SetDuty();
PWM Configuration Example
Timer_Handle_t htim3;

htim3.Instance = TIM3;

htim3.Init.Prescaler = 83;
htim3.Init.Period = 999;

htim3.Channel = TIMER_CHANNEL_1;

htim3.GPIOx = GPIOA;
htim3.Pin = GPIO_PIN_6;
htim3.AFno = 2;

Timer_PWM_Init(&htim3);

Timer_PWM_SetDuty(&htim3, 50);

Timer_PWM_Start(&htim3);

This configuration generates PWM on:

TIM3_CH1 → PA6 → AF2

The PWM driver has been hardware-tested using the NUCLEO-F446RE.

A dedicated PWM waveform is being maintained separately from the timer-interrupt verification evidence.

Servo Motor Control

The PWM driver was extended to support servo motor control.

The servo application uses a nominal:

Frequency = 50 Hz
Period    = 20 ms
Servo Angle Mapping
0°    → approximately 1.0 ms pulse
90°   → approximately 1.5 ms pulse
180°  → approximately 2.0 ms pulse
API
Servo_SetAngle();

A software angle sweep from 0° to 180° and back was also implemented.

ADC Driver

A generalized register-level ADC driver was implemented for the STM32F446RE.

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
Hardware Verification

ADC1 channel 0 on PA0 was tested.

The following measurements were obtained:

PA0 → 3.3 V  → approximately 4093
PA0 → GND    → approximately 1

The ADC output was observed through the UART terminal.

Evidence

ADC verification

SPI Driver

A register-level SPI driver was implemented for the STM32F446RE.

Features
SPI peripheral initialization
Master mode
Clock polarity configuration
Clock phase configuration
Baud-rate prescaler configuration
Software NSS
MSB/LSB first configuration
SPI transmission
SPI status flag handling
Receive data handling
Test Configuration

SPI1 was configured in:

Mode            : Master
CPOL            : 0
CPHA            : 0
SPI Mode        : Mode 0
Bit Order       : LSB First
NSS             : Software

Test data:

uint8_t buffer[] = {0x55, 0xAA, 0xA5};
Loopback Test

For physical verification, MOSI and MISO were connected together.

SPI1
             ┌──────────────┐
PA5 / SCK ──→│ Logic Analyzer│ CH0
PA7 / MOSI ─→│              │ CH1
PA6 / MISO ─→│              │ CH2
             └──────────────┘

PA7 / MOSI ─────────┐
                    │
                    └──── PA6 / MISO
                         (Loopback)

The transmitted data was decoded in PulseView using the SPI protocol decoder.

The loopback test verifies the physical SPI transmit/receive path and signal generation.

This is a loopback verification and does not represent communication with a real SPI slave device.

Evidence

SPI loopback waveform

I2C Driver

A register-level I2C driver has been implemented.

Features
I2C peripheral initialization
GPIO alternate function configuration
Open-drain configuration
I2C clock configuration
START condition generation
STOP condition generation
Address transmission
Data transmission
Status flag handling
Register-level I2C communication

The driver uses:

PB6 → I2C1_SCL
PB7 → I2C1_SDA
AF4
Open-Drain
Current Status

The I2C driver is implemented in the repository.

Hardware verification is currently pending because an external I2C slave device is required for a meaningful communication test.

An I2C bus should not be tested by simply shorting SDA and SCL together.

EEPROM Driver

A register-level EEPROM driver has also been implemented on top of the I2C driver.

The EEPROM driver is intended to provide:

EEPROM initialization
Memory address handling
Data write operations
Data read operations
I2C-based communication

Hardware verification will be performed after an appropriate I2C EEPROM device is available.

Hardware Verification

The project uses actual hardware verification wherever the peripheral behavior can be meaningfully observed.

Peripheral	Verification Method	Status
GPIO	Logic analyzer / PA5 waveform	Verified
EXTI	Button + PA5 waveform	Verified
UART	PC serial terminal	Verified
Timer	Logic analyzer / PA5	Verified
PWM	Logic analyzer	Verified
ADC	UART terminal measurements	Verified
SPI	Logic analyzer + SPI decoder	Verified
I2C	External slave required	Pending
EEPROM	External I2C EEPROM required	Pending
Verification Evidence

Hardware verification evidence is stored inside the docs/ directory.

docs/
├── gpio/
│   └── pa5_waveform.jpeg
│
├── exti/
│   └── exti_button_test.mp4
│
├── adc/
│   └── adc_waveform.jpeg
│
├── uart/
│   └── uart_putty_115200.jpeg
│
├── timer/
│   └── tim2_1s_interrupt_waveform.jpeg
│
├── pwm/
│   └── pwm_verification_reference.jpeg
│
└── spi/
    └── spi_loopback_waveform.jpeg

pwm_verification_reference.jpeg is currently a reference copy and should not be interpreted as the dedicated PWM waveform evidence. A dedicated PWM capture will replace it.

Project Structure

The repository currently follows the STM32CubeIDE project structure.

stm32-driver-library/
│
├── Core/
│   ├── Inc/
│   │   ├── gpio_driver.h
│   │   ├── uart_driver.h
│   │   ├── timer_driver.h
│   │   ├── adc_driver.h
│   │   ├── spi_driver.h
│   │   ├── i2c_driver.h
│   │   └── eeprom_driver.h
│   │
│   └── Src/
│       ├── gpio_driver.c
│       ├── uart_driver.c
│       ├── timer_driver.c
│       ├── adc_driver.c
│       ├── spi_driver.c
│       ├── i2c_driver.c
│       ├── eeprom_driver.c
│       ├── main.c
│       └── stm32f4xx_it.c
│
├── docs/
│   ├── gpio/
│   ├── exti/
│   ├── adc/
│   ├── uart/
│   ├── timer/
│   ├── pwm/
│   └── spi/
│
└── README.md
Development Philosophy
1. Register-Level Understanding

Peripheral configuration is performed through direct register manipulation using CMSIS definitions.

2. Modular Drivers

Each peripheral is implemented as a reusable driver rather than being tied to a single application.

3. Generalization

Drivers are designed to support multiple pins, channels, peripherals, and configurations wherever practical.

4. Hardware Validation

Drivers are tested on the actual STM32F446RE hardware wherever applicable.

5. Incremental Development

Each peripheral is studied from the reference manual and datasheet before implementation and hardware testing.

Current Progress
[x] GPIO Driver
[x] GPIO Input Configuration
[x] GPIO Output Configuration
[x] GPIO Pull-Up / Pull-Down
[x] GPIO Alternate Function
[x] GPIO Analog Configuration

[x] EXTI Driver
[x] SYSCFG Configuration
[x] NVIC Configuration
[x] External Button Interrupt

[x] UART Driver
[x] UART Polling Communication
[x] UART Terminal Testing

[x] Timer Driver
[x] Timer Start/Stop
[x] Timer Counter
[x] Timer Interrupt
[x] Timer-Based Delay

[x] PWM Driver
[x] PWM Duty-Cycle Control
[x] Servo Control

[x] ADC Driver
[x] ADC Hardware Verification

[x] SPI Driver
[x] SPI Loopback Hardware Verification

[x] I2C Driver
[x] EEPROM Driver
[ ] I2C Hardware Verification
[ ] EEPROM Hardware Verification

[ ] CAN Driver
[ ] Watchdog Driver
[ ] RTC Driver
Future Work
Communication Peripherals
Deeper UART driver development
SPI sensor interfacing
I2C sensor interfacing
CAN driver
Communication protocol testing
I2C / EEPROM
Hardware verification using an external I2C EEPROM
ACK polling
EEPROM read/write testing
I2C sensor integration
Advanced Embedded C

Planned development includes:

Function pointers
Callback mechanisms
Macros
Header/source organization
Static libraries
Linking
Makefiles
Embedded C design patterns
Future Embedded Applications

The drivers will be used as building blocks for larger embedded systems projects such as:

Sensor data acquisition
Data logging
Communication systems
Peripheral monitoring
Embedded control applications
Key Technical Skills Demonstrated
Embedded C
ARM Cortex-M4
STM32F4
CMSIS
Memory-mapped registers
GPIO
EXTI
NVIC
UART
Timers
PWM
ADC
SPI
I2C
EEPROM
Interrupt-driven peripherals
Polling-based peripherals
Alternate Function configuration
Hardware debugging
Logic analyzer based verification
PulseView protocol decoding
Git and GitHub
Learning Outcomes

This project has provided practical experience with:

STM32F4 peripheral architecture
ARM Cortex-M4 fundamentals
Memory-mapped I/O
Peripheral clock configuration
Register-level peripheral initialization
Interrupt architecture
EXTI and NVIC
UART communication
Timer operation
PWM generation
ADC conversion
SPI communication
I2C communication
Embedded C driver design
Hardware debugging
Logic analyzer based verification
Modular firmware development
Roadmap
GPIO
  ↓
EXTI / Interrupts
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
EEPROM
  ↓
CAN
  ↓
Advanced Embedded C
  ↓
Sensor / Data Logger Project
  ↓
RTOS

The long-term objective is to build a comprehensive register-level STM32F446 peripheral driver library and use these drivers to develop increasingly complex embedded systems.

Author

Sai Gagan E

B.Tech Electrical Engineering
Maulana Azad National Institute of Technology (MANIT), Bhopal

Repository

This repository contains the complete source code and hardware verification evidence for the project.

The project is continuously being expanded as additional STM32 peripherals and embedded applications are implemented and verified.


### One thing I deliberately changed

I **didn't call the copied timer image actual PWM evidence**. That's important for your GitHub credibility. A recruiter clicking the PWM section should eventually see a real TIM3/PA6 waveform, not a timer-interrupt waveform.

Also, your README now clearly shows this progression:

**Implemented → Hardware verified → Evidence**

That's much stronger for an embedded internship portfolio than simply having a long list of drivers.
