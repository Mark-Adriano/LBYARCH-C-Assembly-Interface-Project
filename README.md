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
| Vector Size (n) | Mode | C Kernel (seconds) | x86-64 ASM Kernel (seconds) |
| :--- | :--- | :--- | :--- |
| **2^20** | Debug (-O0) | 0.002914 | 0.000926 |
| **2^20** | Release (-O3)| 0.000941 | 0.001011 |
| **2^24** | Debug (-O0) | 0.046766 | 0.015250 |
| **2^24** | Release (-O3)| 0.015153 | 0.016300 |
| **2^28** | Debug (-O0) | 0.780771 | 0.252871 |
| **2^28** | Release (-O3)| 0.273423 | 0.257990 |

### Analysis
The program computes the dot product using the formula given in the specs, using functional scalar SIMD instructions for the double-precision floats. The code then successfully implements the testing constraints: evaluating vector sizes ranging from 2^20, 2^24, and 2^28, looping 20 times just for averaging, and then doing a sanity check against the C kernel.



# Correctness Check Output
<img width="935" height="405" alt="Correctness Check Output" src="https://github.com/user-attachments/assets/ba5e260e-02b3-470f-9660-8cbc7d5d2be7" />

# Demo Video
video here
