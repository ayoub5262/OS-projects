# Systems Programming in C - Operating Systems Course

A comprehensive collection of C programming projects demonstrating core operating systems concepts including memory management, process synchronization, multithreading, and system programming fundamentals.

## 🎯 Learning Objectives

This repository showcases practical implementations of:
- **Memory Management Algorithms** (First-Fit, Best-Fit, Next-Fit)
- **Process Synchronization** using semaphores and mutexes
- **Multithreading** with POSIX threads
- **System Programming** with file I/O and process management
- **Image Processing** with PPM format manipulation

## 📁 Project Structure

```
├── assignments/
│   ├── assignment2/          # Basic system programming
│   ├── assignment3/          # Process synchronization & threading
│   ├── assignment4/          # Memory management algorithms
│   └── assignment5/          # Image processing with PPM format
├── utilities/                # Helper programs and demonstrations
├── Makefile                  # Master build configuration
└── README.md                 # This file
```

## 🔧 Technologies Used

- **Language:** C (C11 standard)
- **Build System:** Make
- **Threading:** POSIX threads (pthread)
- **Synchronization:** Semaphores, mutexes
- **Image Processing:** PPM format manipulation
- **System Programming:** Process management, file I/O

## 🚀 Quick Start

### Prerequisites
```bash
# Required tools
gcc          # GNU Compiler Collection with C11 support
make         # Build automation tool
pthread      # POSIX threads library
```

**Supported Platforms:**
- Linux (Ubuntu, Debian, CentOS, etc.)
- macOS with Xcode Command Line Tools
- Windows with WSL2 or MinGW

### Building the Project
```bash
# Clone the repository
git clone <repository-url>
cd <repository-name>

# Build all assignments and utilities
make -f Makefile_Master all

# Build specific assignments
make -f Makefile_Master assignment3
make -f Makefile_Master assignment4

# Clean all build artifacts
make -f Makefile_Master clean

# Get help with available targets
make -f Makefile_Master help
```

## 📚 Assignments Overview

### Assignment 2: System Programming Fundamentals
**Location:** `assignments/assignment2/`

| Program | Description |
|---------|-------------|
| `file_operations_advanced.c` | Advanced file I/O operations and error handling |
| `system_programming_extended.c` | System calls and process management |
| `thread_bag_distribution.c` | Basic multithreading with shared resources |

**Key Concepts:** File I/O, error handling, basic threading

### Assignment 3: Process Synchronization & Threading
**Location:** `assignments/assignment3/`

| Program | Description |
|---------|-------------|
| `semaphore_basic_synchronization.c` | Basic semaphore usage for process coordination |
| `semaphore_advanced_patterns.c` | Complex synchronization patterns |
| `multithread_exam_system.c` | Multi-threaded exam grading simulation |
| `exam_grading_framework.h/.c` | Shared framework for threading exercises |

**Key Concepts:** Semaphores, mutexes, producer-consumer patterns, deadlock prevention

### Assignment 4: Memory Management Algorithms
**Location:** `assignments/assignment4/`

| Algorithm | Files | Description |
|-----------|-------|-------------|
| **First-Fit** | `memory_allocator_first_fit.c/.h` | Allocates first available block |
| **Best-Fit** | `memory_allocator_best_fit.c/.h` | Finds smallest suitable block |
| **Next-Fit** | `memory_allocator_next_fit.c/.h` | Continues from last allocation |
| **Advanced** | `memory_manager_advanced.c/.h` | Extended memory management features |

**Testing:** Comprehensive test suites in `test_*.c` files

**Key Concepts:** Dynamic memory allocation, fragmentation analysis, performance optimization

### Assignment 5: Image Processing with PPM Format
**Location:** `assignments/assignment5/`

| Program | Description |
|---------|-------------|
| `ppm_image_reader.c` | PPM format parsing and basic operations |
| `image_transformation_engine.c` | Geometric transformations (rotate, scale, flip) |
| `image_filter_processor.c` | Image filtering (blur, sharpen, edge detection) |
| `advanced_image_processor.c` | Complex image processing operations |

**Sample Images:** Various PPM test files included for validation

**Key Concepts:** Image format parsing, pixel manipulation, algorithmic image processing

### Utility Programs
**Location:** `utilities/`

| Program | Description |
|---------|-------------|
| `interactive_shell_menu.c` | Interactive command-line menu system |
| `interactive_menu_advanced.c` | Advanced menu with extended functionality |
| `prime_number_generator.c` | Basic prime number generation |
| `prime_number_advanced.c` | Optimized prime number algorithms |
| `process_fork_demonstration.c` | Process forking and child process management |

## 🛠️ Technical Implementation

### Memory Management Architecture
- **Allocation Strategies:** Implements and compares first-fit, best-fit, and next-fit algorithms
- **Fragmentation Analysis:** Tracks internal and external fragmentation
- **Performance Metrics:** Measures allocation speed and memory utilization
- **Thread Safety:** Synchronized access to memory pools in multi-threaded environments

### Synchronization Mechanisms
- **Semaphores:** Binary and counting semaphores for resource management
- **Mutexes:** Mutual exclusion for critical sections
- **Condition Variables:** Thread coordination and signaling
- **Producer-Consumer Patterns:** Classic synchronization problems

### Image Processing Pipeline
- **Format Support:** PPM (Portable Pixmap) format parsing
- **Pixel Operations:** RGB manipulation and color space conversions
- **Filtering Algorithms:** Convolution-based filters (blur, sharpen, edge detection)
- **Geometric Transformations:** Rotation, scaling, and mirroring operations

## 🏗️ Build System & Configuration

### Master Makefile
The `Makefile_Master` provides a unified build system:

```bash
# Available targets
make -f Makefile_Master all          # Build all projects
make -f Makefile_Master assignments  # Build all assignments only
make -f Makefile_Master utilities    # Build utilities only
make -f Makefile_Master assignment3  # Build specific assignment
make -f Makefile_Master clean        # Remove all build artifacts
make -f Makefile_Master help         # Show available targets
```

### Compiler Configuration
- **Standard:** C11 (`-std=c11`)
- **Warnings:** Comprehensive warning flags (`-Wall -Wpedantic`)
- **Threading:** POSIX threads support (`-pthread`)
- **Debug:** Debug symbols for development (`-g`)
- **Optimization:** Configurable optimization levels

## 🧪 Testing & Validation

### Automated Testing
Each assignment includes comprehensive test suites:

| Assignment | Test Files | Coverage |
|------------|------------|----------|
| **Assignment 4** | `test_first_fit_allocator.c`<br>`test_best_fit_allocator.c`<br>`test_advanced_memory_manager.c` | Memory allocation algorithms<br>Fragmentation analysis<br>Performance benchmarks |
| **Assignment 5** | Sample PPM images<br>`sample_*.ppm` files | Image processing validation<br>Format parsing<br>Transformation accuracy |

### Manual Testing
- **Interactive Menus:** User-driven testing through menu systems
- **Visual Validation:** PPM images can be viewed to verify processing results
- **Performance Analysis:** Built-in timing and memory usage reporting

## 📊 Performance Considerations

### Memory Allocation Performance
- **First-Fit:** O(n) average case, fast allocation
- **Best-Fit:** O(n) search time, optimal space utilization
- **Next-Fit:** O(1) amortized, balanced approach

### Threading Performance
- **Minimal Synchronization Overhead:** Efficient use of semaphores and mutexes
- **Scalable Design:** Performance scales with number of processor cores
- **Load Balancing:** Work distribution across multiple threads

### Image Processing Optimization
- **Memory Efficient:** In-place operations where possible
- **Cache Friendly:** Sequential memory access patterns
- **Parallel Processing Ready:** Algorithms designed for parallelization

## 🎓 Educational Value

### Core Computer Science Concepts
- **Operating Systems:** Process management, memory management, synchronization
- **Systems Programming:** Low-level programming, system calls, error handling
- **Algorithms:** Implementation and analysis of classic algorithms
- **Software Engineering:** Modular design, testing strategies, documentation

### Practical Skills Developed
- **C Programming Mastery:** Advanced C features, memory management, debugging
- **Concurrent Programming:** Thread safety, synchronization primitives
- **Performance Analysis:** Profiling, optimization, benchmarking
- **Software Development:** Version control, build systems, testing

## � Requirements & Dependencies

### System Requirements
- **Operating System:** Linux, macOS, or Windows with WSL2
- **Compiler:** GCC 7.0+ with C11 support
- **Build Tool:** GNU Make 4.0+
- **Memory:** Minimum 512MB RAM for compilation

### Development Dependencies
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# CentOS/RHEL
sudo yum groupinstall "Development Tools"

# macOS
xcode-select --install

# Windows WSL2
# Install Ubuntu from Microsoft Store, then use Ubuntu commands
```

## 🔒 License & Academic Use

### Educational Purpose
This repository contains academic coursework designed for educational purposes. The code demonstrates fundamental concepts in systems programming and operating systems.

### Usage Guidelines
- ✅ **Learning Reference:** Use as a learning resource for understanding concepts
- ✅ **Code Study:** Analyze implementation techniques and patterns
- ✅ **Inspiration:** Draw inspiration for your own implementations
- ❌ **Direct Copying:** Do not copy code for academic submissions
- ❌ **Academic Dishonesty:** Respect your institution's academic integrity policies

### Disclaimer
- **No Warranty:** Code provided "as-is" for educational demonstration
- **Academic Integrity:** Users responsible for following their institution's policies
- **Learning Focus:** Intended to supplement, not replace, coursework

## 🤝 Contributing

While this is primarily an academic repository, improvements are welcome:

1. **Bug Reports:** Open issues for any bugs or compilation problems
2. **Documentation:** Improve comments, README, or add examples
3. **Code Quality:** Suggest improvements for code clarity or performance
4. **Cross-Platform:** Help with Windows/macOS compatibility

### Development Setup
```bash
git clone <repository-url>
cd <repository-name>
make -f Makefile_Master all
make -f Makefile_Master assignment4  # Test specific assignment
```

## 🚀 Getting Started

### For Students
1. **Study the Structure:** Understand the project organization
2. **Build and Test:** Compile all assignments to ensure environment setup
3. **Explore Code:** Read through implementations to understand concepts
4. **Run Examples:** Execute programs to see algorithms in action

### For Educators
1. **Course Integration:** Use as supplementary material for OS courses
2. **Assignment Templates:** Adapt structure for your own assignments
3. **Concept Demonstration:** Use specific programs to illustrate concepts
4. **Assessment Ideas:** Reference implementation approaches for grading

---

## 🏆 Skills Demonstrated

| Category | Technologies & Concepts |
|----------|------------------------|
| **Programming Languages** | C11, POSIX C, GNU C Extensions |
| **System Programming** | Process management, file I/O, system calls |
| **Concurrent Programming** | POSIX threads, semaphores, mutexes, condition variables |
| **Memory Management** | Dynamic allocation, custom allocators, fragmentation analysis |
| **Algorithms** | Sorting, searching, image processing, optimization |
| **Tools & Build Systems** | GCC, Make, debugging tools, performance profilers |
| **Software Engineering** | Modular design, testing, documentation, version control |

---

*This repository demonstrates practical application of fundamental computer science concepts in systems programming, showcasing both theoretical understanding and implementation skills essential for operating systems development.*
