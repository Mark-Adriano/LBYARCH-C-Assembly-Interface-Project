# LBYARCH x86-to-C interface programming project
**Repository:** LBYARCH-C-Assembly-Interface-Project

## Group Members
* **Adriano, Mark Luis B.**
* **Pallarca, Cedric S.**

## Project Description
This project implements a dot product calculation between two vectors (Vector A and Vector B) using double-precision floating-point numbers. The kernel is written in two versions to compare performance:
1. A standard **C program**.
2. An **x86-64 Assembly language** program utilizing functional scalar SIMD registers and instructions (`xmm`, `movsd`, `mulsd`, `addsd`).

## How to Run
To run this project, ensure you have **NASM** and a C compiler (like **GCC/MinGW**) installed and added to your system's PATH.

**1. Assemble the NASM file into a Windows 64-bit object file:**
```bash
nasm -f win64 asm_kernel.asm -o asm_kernel.obj
```

**2. Compile the C code and link the object file:**
```bash
gcc main.c asm_kernel.obj -o main.exe
```

(If you are testing **Release** mode optimizations, add the `-O3` flag to your GCC command: `gcc -O3 main.c asm_kernel.obj -o main.exe`)

**3. Run the compiled executable:**
```bash
main.exe
```

# Execution Time Comparison

### Analysis

# Correctness Check Output
picture of output here

# Demo Video
video here
