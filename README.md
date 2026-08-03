# STM32 Register-Level Driver Library

This repository contains register-level peripheral drivers developed for the STM32F446RE without using HAL peripheral drivers.

---

## Hardware Used

- STM32 NUCLEO-F446RE
- STM32CubeIDE
- ST-Link Debugger
- PuTTY Serial Terminal

---

## Drivers Completed

- ✅ RCC Driver
- ✅ GPIO Driver
- ✅ EXTI Driver
- ✅ UART Driver

---

## Projects Completed

- ✅ Button Interrupt Project
- ✅ UART Echo Project
- ✅ UART Terminal Project

---

## Upcoming Drivers

- ⬜ Timer
- ⬜ PWM
- ⬜ ADC
- ⬜ SPI
- ⬜ I²C
- ⬜ Watchdog

---

## Repository Structure

```text
Core/
├── Inc/
│   ├── gpio_driver.h
│   ├── rcc_driver.h
│   └── uart_driver.h
│
└── Src/
    ├── gpio_driver.c
    ├── rcc_driver.c
    ├── uart_driver.c
    └── main.c
```

---

## Development Approach

- Register-level programming
- No HAL peripheral drivers
- Modular driver architecture
- Reusable embedded drivers

---

## Author

**Sai Gagan E**

B.Tech Electrical Engineering

MANIT Bhopal
