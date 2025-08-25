# Assignment 4 - Memory Management

Implementation of various memory allocation algorithms with comprehensive testing.

## Files

### Core Implementation
- **4a.c/4a.h**: First-fit memory allocation algorithm
- **4b.c/4b.h**: Best-fit memory allocation algorithm  
- **4extended.c/4extended.h**: Extended memory management features
- **nextfit.c/nextfit.h**: Next-fit algorithm implementation

### Testing
- **test_4a.c**: Test suite for first-fit algorithm
- **test_4b.c**: Test suite for best-fit algorithm
- **test_4extended.c**: Test suite for extended features

### Build System
- **Makefile**: Comprehensive build configuration
- **deps.mk**: Dependency management

## Memory Allocation Algorithms

### First-Fit (4a)
- Allocates memory in the first available block that fits
- Fast allocation with O(n) average complexity
- Can lead to external fragmentation

### Best-Fit (4b) 
- Finds the smallest block that fits the request
- Minimizes wasted space per allocation
- Higher search overhead but better memory utilization

### Next-Fit
- Variant of first-fit starting from last allocated position
- Reduces search time for sequential allocations
- Good performance for programs with locality

### Extended Features (4extended)
- Advanced memory management capabilities
- Memory coalescing and defragmentation
- Performance monitoring and statistics

## Key Features

### Memory Safety
- Comprehensive bounds checking
- Double-free detection
- Memory leak tracking
- Corruption detection

### Performance Optimization
- Efficient free list management
- Minimal overhead per allocation
- Fast coalescing of adjacent free blocks

### Testing Framework
- Comprehensive test suites for each algorithm
- Stress testing with various allocation patterns
- Performance benchmarking
- Memory usage analysis

## Building and Testing

```bash
# Build all components
make all

# Build specific algorithms
make 4a 4b 4extended nextfit

# Build and run tests
make test_4a test_4b test_4extended

# Run tests
./test_4a
./test_4b  
./test_4extended

# Clean build artifacts
make clean
```

## Performance Characteristics

| Algorithm | Allocation Speed | Memory Efficiency | Fragmentation |
|-----------|------------------|-------------------|---------------|
| First-Fit | Fast             | Good              | Moderate      |
| Best-Fit  | Slower           | Excellent         | Low           |
| Next-Fit  | Fast             | Good              | Moderate      |

## Learning Objectives

- Understanding different memory allocation strategies
- Implementing efficient data structures for memory management
- Performance analysis and optimization techniques
- Comprehensive testing and validation methods
- Memory safety and error detection
