
# STM32F103C8T6 (Blue Pill) Driver Development

Well‑structured, hardware‑abstraction drivers for the STM32F103C8T6 ("Blue Pill") microcontroller. Clean, modular codebase showcasing a full set of essential peripheral drivers.

## 📦 Repository Overview

This repository includes:

* **HAL-inspired drivers** tailored for STM32F103C8T6.
* Full-featured modules: **GPIO**, **USART**, **SPI**, **I2C**, **ADC**, **Timers**, **bxCAN**.
* **CMSIS‑compliant core setup** for easier migration and scalability.
* A **Makefile‑based build system**, compatible out-of-the-box with common toolchains (SW4STM32, Keil, gcc-arm-none-eabi + Eclipse).

## 🔍 What’s Inside

### Driver Modules

* **GPIO** – Configurable input/output, alternate-function, pull-up/down, speed control.
* **USART1/2** – UART communication (init, blocking/non-blocking TX/RX, interrupts).
* **SPI1/2** – Full‑duplex master/slave support, polling and DMA-ready.
* **I2C1** – Master‑mode communication: address reading/writing, ACK/NACK handling.
* **ADC1** – Single and continuous conversions with interrupt support.
* **TIM2/3/4**, **SysTick** – Timer initialization, interrupts, PWM generation.
* **bxCAN** – CAN Communication.

#### Key Features

* **Initialization APIs** driven by config structs for each peripheral.
* **Blocking & non-blocking modes**: supports polling, interrupts, and DMA targets.
* **Error/status callbacks** for robust operation.

### System Core

* **CMSIS/Core** support for STM32F103xx.
* **Flexible clock setup** via PLL with configurable HCLK/PCLK prescalers.
* **Nested Vectored Interrupt Controller (NVIC)** utilities for clean interrupt handling.

## 🛠 Getting Started

1. **Clone the repo**

   ```bash
   git clone https://github.com/Tanishq0305/STM32_F103C8T6.git
   cd STM32_F103C8T6
   ```

2. **Choose an example** (e.g. `uart_echo`) and open it in your IDE of choice (SW4STM32, Keil, or Eclipse + Makefile).

3. **Build & Flash**

   * Via Makefile:

     ```bash
     make BOARD=STM32F103C8T6
     make flash
     ```
   * Or import into your preferred IDE and flash as usual.

## ✅ What’s Complete

* Core peripheral drivers: GPIO, USART, SPI, I2C, ADC, Timers, EXTI.
* Cross-toolchain build infrastructure and consistent CMSIS support.
* Functional, tested examples proving reliability and reusability.
* Clean, expandable architecture—easy to grow and document.

## 🔭 Roadmap & Future Plans

Next steps include:

* **Full DMA support** across SPI, USART, ADC.
* Integration of **power modes** and **RTC driver**.
* **RTOS compatibility**: thread-safe APIs, semaphore/queue support (e.g. FreeRTOS).
* Adding **peripherals**: CAN, USB (via USB fly library), SDIO.
* **Unit tests & CI**: GitHub Actions scripts for build/test automation.
* **Documentation**: Doxygen comments, user guides in a `/docs` folder.

