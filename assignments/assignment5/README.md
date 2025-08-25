# Assignment 5 - Image Processing

Implementation of image processing operations using the PPM (Portable Pixmap) format.

## Files

### Core Programs
- **a5_a.c**: PPM image reading and basic operations
- **a5_b.c**: Image manipulation and transformations  
- **a5_c.c**: Image filtering and effects
- **a5_d.c**: Advanced image processing operations

### Sample Images
- **beispiel1.ppm**, **beispiel2.ppm**: Basic test images
- **beispiel_b.ppm**, **beispiel_c.ppm**: Specific test cases
- **beispiel_kreis.ppm**: Circle test image
- **beispiel_test.ppm**: General testing image
- **test_kreis.ppm**: Circle validation image

### Documentation
- **antworten.txt**: Assignment answers and explanations

## Image Processing Features

### Basic Operations (a5_a)
- PPM file format parsing
- Image loading and validation
- Basic pixel manipulation
- Memory management for large images

### Transformations (a5_b)
- Image scaling and resizing
- Rotation and flipping operations
- Color space conversions
- Geometric transformations

### Filtering (a5_c)  
- Blur and sharpening filters
- Edge detection algorithms
- Noise reduction techniques
- Custom convolution kernels

### Advanced Processing (a5_d)
- Complex image effects
- Multi-pass processing
- Performance optimizations
- Advanced algorithms

## PPM Format Support

### Format Specifications
- **P3**: ASCII PPM format support
- **P6**: Binary PPM format support  
- RGB color space (24-bit)
- Arbitrary image dimensions

### Features
- Robust header parsing
- Error handling for malformed files
- Memory-efficient processing
- Large image support

## Key Concepts

### Image Representation
- Pixel-based image storage
- RGB color model understanding
- Memory layout optimization
- Efficient data access patterns

### Algorithm Implementation
- Convolution operations
- Spatial domain filtering
- Geometric transformations
- Color manipulation

### Performance Optimization
- Cache-friendly memory access
- Vectorization opportunities
- Memory usage optimization
- Processing pipeline efficiency

## Building and Running

```bash
# Build all programs
make all

# Build individual programs
gcc -o a5_a a5_a.c
gcc -o a5_b a5_b.c  
gcc -o a5_c a5_c.c
gcc -o a5_d a5_d.c

# Run with sample images
./a5_a beispiel1.ppm
./a5_b beispiel2.ppm output.ppm
./a5_c beispiel_test.ppm filtered.ppm
./a5_d beispiel_kreis.ppm processed.ppm
```

## Sample Operations

### Image Loading
```bash
./a5_a beispiel1.ppm          # Load and display image info
```

### Image Transformation  
```bash
./a5_b input.ppm output.ppm   # Apply transformations
```

### Filtering
```bash
./a5_c input.ppm filtered.ppm # Apply filters
```

### Advanced Processing
```bash
./a5_d input.ppm result.ppm   # Advanced operations
```

## Learning Objectives

- Understanding digital image representation
- Implementing efficient image processing algorithms
- Working with binary file formats
- Memory management for large data sets
- Performance optimization techniques
- Algorithm analysis and complexity
