# Project README

## Overview
This project is a simple operating system kernel written in C. It includes basic functionalities such as VGA text output, dynamic memory allocation, and interrupt handling.

## Features
- VGA Text Output (80x25)
- Dynamic Memory Allocation (`kmalloc`, `kfree`)
- Interrupt Handling (default handler for all interrupts, page fault handler)

## Project Structure
### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools

## Build & Run
### Linux Build
1. Navigate to the project directory:
   ```sh
   cd <Project>
   ```
2. Build the project:
   ```sh
   make -f Makefile.linux all
   ```
3. To clean and rebuild:
   ```sh
   make -f Makefile.linux clean
   make -f Makefile.linux all
   ```
4. Run the kernel (assuming it is booted from a bootloader like QEMU):
   ```sh
   qemu-system-x86_64 build/kernel
   ```

### Windows Build
1. Navigate to the project directory:
   ```sh
   cd <Project>
   ```
2. Build the project:
   ```sh
   make -f Makefile.windows all
   ```
3. To clean and rebuild:
   ```sh
   make -f Makefile.windows clean
   make -f Makefile.windows all
   ```

### Wine Build (Cross-Compile for Windows)
1. Navigate to the project directory:
   ```sh
   cd <Project>
   ```
2. Build the project:
   ```sh
   make -f Makefile.wine all
   ```
3. To clean and rebuild:
   ```sh
   make -f Makefile.wine clean
   make -f Makefile.wine all
   ```

### WebAssembly Build (Emscripten)
1. Navigate to the project directory:
   ```sh
   cd <Project>
   ```
2. Build the project:
   ```sh
   make -f Makefile.web all
   ```
3. To clean and rebuild:
   ```sh
   make -f Makefile.web clean
   make -f Makefile.web all
   ```

Each of these makefiles provides a straightforward way to build the kernel for different platforms. The `all` target builds the project, while the `clean` target removes any build artifacts.