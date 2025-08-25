# Assignment 3: Process Synchronization & Threading

This assignment demonstrates fundamental concepts in concurrent programming, focusing on process synchronization using semaphores, mutexes, and advanced threading patterns.

## 📋 Overview

The assignment implements a multi-threaded exam grading system that showcases:
- **Basic Synchronization**: Using semaphores for resource management
- **Advanced Patterns**: Complex synchronization scenarios
- **Multi-threaded Processing**: Parallel exam grading simulation

## 🏗️ Architecture

### Core Framework
- **`exam_grading_framework.h/.c`**: Shared framework providing common data structures and utility functions for all threading exercises

### Program Components

| Program | Purpose | Key Concepts |
|---------|---------|--------------|
| `semaphore_basic_synchronization.c` | Basic semaphore usage for coordinating worker threads | Binary semaphores, mutual exclusion |
| `semaphore_advanced_patterns.c` | Complex synchronization patterns | Producer-consumer, resource pools |
| `multithread_exam_system.c` | Complete multi-threaded exam processing system | Thread pools, work distribution |

## 🚀 Building and Running

### Build All Programs
```bash
make all
```

### Build Individual Programs
```bash
make semaphore_basic_sync
make semaphore_advanced_patterns  
make multithread_exam_system
```

### Clean Build Artifacts
```bash
make clean
```

## 🧵 Threading Concepts Demonstrated

### 1. Basic Synchronization (`semaphore_basic_synchronization.c`)
- **Semaphore Initialization**: Creating and configuring semaphores
- **Worker Coordination**: Synchronizing multiple threads working on shared resources
- **Critical Sections**: Protecting shared data structures
- **Thread Lifecycle**: Creating, managing, and joining threads

### 2. Advanced Patterns (`semaphore_advanced_patterns.c`)
- **Producer-Consumer Pattern**: Classic synchronization problem implementation
- **Resource Pool Management**: Managing limited resources across multiple threads
- **Deadlock Prevention**: Strategies to avoid circular wait conditions
- **Performance Optimization**: Minimizing synchronization overhead

### 3. Multi-threaded System (`multithread_exam_system.c`)
- **Thread Pool Architecture**: Reusable worker threads for processing tasks
- **Work Distribution**: Load balancing across available threads
- **Result Aggregation**: Collecting and combining results from multiple threads
- **Error Handling**: Graceful handling of threading errors and exceptions

## 🔧 Technical Implementation

### Synchronization Primitives Used
- **Semaphores**: For counting resources and signaling between threads
- **Mutexes**: For mutual exclusion in critical sections
- **Condition Variables**: For thread coordination and signaling

### Key Features
- **Thread Safety**: All shared data structures are properly synchronized
- **Performance**: Efficient use of synchronization primitives
- **Scalability**: Design scales with number of available CPU cores
- **Robustness**: Comprehensive error handling and resource cleanup

## 🧪 Testing and Validation

### Interactive Testing
All programs are designed to be interactive, allowing users to:
- Configure the number of threads
- Set processing parameters
- Observe synchronization behavior in real-time
- Monitor performance metrics

### Validation Points
- **Correctness**: Verify that all processing completes without data races
- **Performance**: Measure speedup achieved through parallelization
- **Resource Usage**: Monitor memory and CPU utilization
- **Synchronization**: Ensure proper coordination between threads

## 🎓 Learning Objectives

After completing this assignment, students will understand:
- How to design and implement thread-safe programs
- When and how to use different synchronization primitives
- Common concurrency patterns and their implementations
- Performance implications of concurrent programming
- Debugging and testing techniques for multi-threaded programs

---

*This assignment provides hands-on experience with fundamental concurrent programming concepts essential for systems programming and operating systems development.*
- Workers coordinate access to shared resources
- No race conditions occur
- System responds properly to shutdown signals
- Resource cleanup happens automatically

## Learning Objectives

- Understanding semaphore-based synchronization
- Implementing thread-safe concurrent programs
- Managing shared resources in multi-threaded environments
- Proper error handling in system programming
