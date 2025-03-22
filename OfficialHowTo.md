# **Spherecore Compiler: Maximum How-To User Guide**

This user guide provides a **step-by-step overview** of using and understanding the Spherecore Compiler, from installation to executing compiled programs. It includes explanations of syntax, commands, memory management, debugging, optimizations, and output handling.

---

## **Table of Contents:**
1. **Introduction to Spherecore Compiler**
   - What is Spherecore?
   - Key Features (AOT Compilation, JIT Execution, SIMD Optimizations)
   - Supported Platforms (Windows x64, Ryzen 3)

2. **Installation**
   - Prerequisites
   - Downloading and Setting Up Spherecore Compiler
   - Building from Source

3. **Spherecore Syntax**
   - Basic Syntax Rules
   - Data Types and Variables
   - Functions and Procedures
   - Loops, Conditionals, and Recursion
   - Inline Assembly Support

4. **Using the Compiler**
   - Writing Your First Spherecore Program
   - Compiling with AOT Mode
   - Executing with JIT Mode
   - Generating Executables

5. **Memory Management**
   - Registers, Heap, and Stack
   - Allocating and Accessing Memory
   - Pointer Arithmetic and Register Handling

6. **Compiler Optimizations**
   - AVX2 SIMD Optimization (for Ryzen 3)
   - Zero-Copy Memory Transfers
   - Performance Profiling and Execution Tracing

7. **Debugging and Diagnostics**
   - Real-Time Debugging Hooks
   - Breakpoints and Watch Variables
   - Error Handling and Diagnostics Output

8. **Advanced Features**
   - Custom Inline Assembly
   - GPU Acceleration
   - Parallel Execution and Threading

9. **Sample Programs**
   - Spherecore "Hello World"
   - Loops and Conditionals
   - Recursive Functions and Memory Allocation
   - Optimized Mathematical Computations with SIMD

10. **FAQ and Troubleshooting**
   - Common Errors and Fixes
   - Performance Tuning Tips
   - Future Roadmap

---

## **1. Introduction to Spherecore Compiler**

### **What is Spherecore?**
Spherecore is an **assembly-optimized C++ compiler** designed for **speed, low-level performance, and advanced memory handling** on **x64 Ryzen 3 systems (Windows)**. Spherecore aims to balance **Ahead-of-Time (AOT) Compilation** with **Just-In-Time (JIT) execution**, allowing users to compile both static binaries and dynamically optimized machine code at runtime.

### **Key Features:**
- **AOT and JIT Compilation**: Compile programs into **.exe binaries** or execute them on-the-fly using JIT.
- **Low-Level Memory Access**: Direct manipulation of stack, heap, and CPU registers.
- **SIMD Optimizations (AVX2)**: Leverage **SIMD instructions for parallel processing**, optimized for Ryzen 3 CPUs.
- **Inline Assembly Support**: Integrate low-level assembly code for maximum control over the CPU.
- **Diagnostics and Debugging**: Real-time debugging hooks, execution tracing, and error diagnostics.

---

## **2. Installation**

### **Prerequisites:**
Before installing the Spherecore Compiler, ensure that your system meets the following requirements:
- **Operating System**: Windows 10/11 (x64)
- **Processor**: AMD Ryzen 3 or higher
- **RAM**: Minimum 8 GB (16 GB recommended)
- **Software Requirements**:
  - Visual Studio (with C++ build tools)
  - CMake (for building the compiler)
  - Python (optional, for testing scripts)
  - NASM (Netwide Assembler, for low-level assembly support)

### **Installation Steps:**
1. **Download the Source Code**:
   - Clone the Spherecore Compiler repository:
     ```bash
     git clone https://github.com/yourusername/spherecore-compiler.git
     cd spherecore-compiler
     ```

2. **Build the Compiler**:
   - Run CMake to configure the build:
     ```bash
     cmake -B build -G "Visual Studio 17 2022"
     ```
   - Build the project:
     ```bash
     cmake --build build --config Release
     ```

3. **Add to PATH (Optional)**:
   - Add the compiler binary to your system PATH for easy access:
     ```bash
     setx PATH "%PATH%;C:\path\to\spherecore-compiler\build\Release"
     ```

---

## **3. Spherecore Syntax**

Spherecore combines high-level syntax with low-level assembly-like control. Below are key elements of the language syntax:

### **Basic Syntax Rules:**
- **Semicolon-Free Statements**: No semicolons are required to terminate statements.
- **Indent-Based Blocks**: Similar to Python, indentation defines code blocks.
- **Variables and Constants**:
  - `define`: Declare and initialize a constant.
  - `var`: Declare a mutable variable.

### **Example: Declaring Variables**
```spherecore
define MAX_SIZE 1024
var counter = 0
```

### **Functions and Procedures:**
- **Function Declaration and Return Values**:
```spherecore
fn add(a, b)
    return a + b
```

### **Loops and Conditionals:**
```spherecore
for i in 0..MAX_SIZE
    if i % 2 == 0
        print("Even number: ", i)
```

---

## **4. Using the Compiler**

### **Writing and Running Your First Spherecore Program:**
1. **Create a new file, `main.sphe`:**
   ```spherecore
   define HELLO "Hello, Spherecore!"
   print(HELLO)
   ```

2. **Compile the Program (AOT Mode):**
   ```bash
   spherecorec main.sphe -o main.exe
   ```

3. **Run the Executable:**
   ```bash
   main.exe
   ```

4. **Run with JIT Mode (Direct Execution):**
   ```bash
   spherecorec main.sphe --jit
   ```

---

## **5. Memory Management**

Spherecore allows fine-grained control over memory, including registers, heap, and stack.

### **Registers:**
- Directly manipulate CPU registers (RAX, RBX, RCX, etc.).
- Example:
  ```spherecore
  asm {
      MOV RAX, 10
      ADD RAX, 20
  }
  ```

### **Heap and Stack Allocation:**
- Use built-in functions to allocate and free memory:
  ```spherecore
  ptr = malloc(256)  // Allocate 256 bytes on the heap
  free(ptr)
  ```

---

## **6. Compiler Optimizations**

### **SIMD Optimizations (AVX2 for Ryzen 3)**:
Spherecore leverages AVX2 instructions for parallel computations:
```spherecore
fn vector_add(a[], b[])
    result = avx2_add(a, b)
    return result
```

---

## **7. Debugging and Diagnostics**

- **Real-Time Debugging Hooks**: Add breakpoints and trace execution:
  ```bash
  spherecorec --debug main.sphe
  ```
- **Diagnostics Output**: View error messages and execution logs.

---

## **8. Advanced Features**

- **Inline Assembly**: Mix Spherecore code with low-level x64 assembly.
- **GPU Acceleration**: Leverage GPU for parallel execution (future feature).
- **Multithreading and Parallelism**: Execute tasks concurrently.

---

## **9. Sample Programs**

### **Hello World:**
```spherecore
define MESSAGE "Hello, Spherecore World!"
print(MESSAGE)
```

---

## **10. FAQ and Troubleshooting**
**Q: How do I fix a segmentation fault error?**  
A: Check for invalid memory access and use diagnostics to trace the issue.  

**Q: How can I improve compilation speed?**  
A: Enable multi-threaded AOT compilation with `-j` flag:  
```bash
spherecorec main.sphe -o main.exe -j 4
```  

---

This guide is your comprehensive resource for mastering Spherecore Compiler.
