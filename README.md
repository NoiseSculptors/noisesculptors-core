# Noise Sculptors Core

**Noise Sculptors Core** provides low-level firmware modules shared between multiple Noise Sculptors products.

It implements only a **subset** of each MCU’s functionality — just enough to initialize clocks, handle timing (DWT / delay), interrupts, basic I/O, and serial communication, etc.

At this stage it serves as a **common core** for Noise Sculptors boards, projects and prototypes.

---

## Supported Microcontrollers

**STM32H750** Used by *Calibrator750*, *Rocket Calibrator*, and related projects.
Coming soon - **STM32L431** used by *Herztick*.

Additional Cortex-M families may be added later as the ecosystem grows.

---

## Structure

```

include/750/         # Public headers
src/h750/            # Core source files
startup/h750/        # Startup code (flash / SRAM)
ldscripts/h750/      # Linker scripts and memory maps

````

Each supported MCU family has its own subfolder (e.g. `h750/`, `l431/`).

---

## Building

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=cmake/arm-none-eabi-gcc.cmake -DMCU=h750 -DRUN=axi
cmake --build build
```

---

## Use in Products

Add this repository as a **submodule** to your product (explained in product's ```README.md```).

---

© Noise Sculptors [https://noisesculptors.com](https://noisesculptors.com)

