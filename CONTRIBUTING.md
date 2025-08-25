# Contributing to Systems Programming Course Repository

Thank you for your interest in contributing to this educational repository! While this primarily contains academic coursework, we welcome improvements that enhance the learning experience.

## 🎯 Types of Contributions Welcome

### ✅ Encouraged Contributions
- **Bug Fixes**: Corrections to compilation errors or runtime issues
- **Documentation**: Improvements to README files, code comments, or examples
- **Cross-Platform Support**: Enhancements for Windows, macOS, or other platforms
- **Code Quality**: Refactoring for better readability or performance
- **Build System**: Improvements to Makefiles or build processes
- **Testing**: Additional test cases or validation scripts

### ⚠️ Please Avoid
- **Complete Reimplementations**: Major algorithmic changes that alter learning objectives
- **Style Changes Only**: Purely cosmetic changes without functional benefit
- **Solution Spoilers**: Adding complete solutions that undermine educational value

## 🚀 Getting Started

### Development Setup
```bash
# Clone the repository
git clone <repository-url>
cd <repository-name>

# Test the build system
make all

# Run tests
make test
```

### Prerequisites
- GCC with C11 support
- GNU Make
- POSIX threads library
- Basic understanding of systems programming concepts

## 📝 Contribution Guidelines

### Code Style
- **C Standard**: Use C11 standard features
- **Naming**: Use descriptive variable and function names
- **Comments**: Document complex algorithms and synchronization patterns
- **Memory Management**: Ensure proper allocation/deallocation
- **Thread Safety**: Maintain thread-safe operations where applicable

### Commit Guidelines
```bash
# Good commit messages
git commit -m "Fix memory leak in best-fit allocator"
git commit -m "Add cross-platform support for Assignment 3"
git commit -m "Improve README documentation for Assignment 4"

# Use present tense and imperative mood
git commit -m "Add validation for PPM image headers"
```

### Pull Request Process
1. **Fork** the repository
2. **Create** a feature branch: `git checkout -b feature/your-feature-name`
3. **Make** your changes with appropriate tests
4. **Update** documentation if needed
5. **Ensure** all tests pass: `make test`
6. **Submit** a pull request with a clear description

## 🧪 Testing Guidelines

### Before Submitting
- [ ] All assignments compile without warnings
- [ ] Existing functionality remains intact
- [ ] New features include appropriate documentation
- [ ] Cross-platform compatibility considered
- [ ] Memory leaks checked (valgrind if available)

### Test Your Changes
```bash
# Build everything
make clean && make all

# Test specific assignments
make assignment3
make assignment4 && cd assignments/assignment4 && make test-all

# Validate build outputs
make validate
```

## 📚 Educational Considerations

### Maintaining Learning Value
- **Preserve Complexity**: Don't oversimplify concepts that students need to learn
- **Add Context**: Include comments explaining why certain approaches are used
- **Educational Comments**: Add pedagogical notes for complex concepts
- **Incremental Learning**: Maintain the progression from simple to complex

### Academic Integrity
- Improvements should enhance learning, not provide shortcuts
- Maintain the educational challenge level
- Document changes that might affect learning outcomes

## 🔍 Review Process

### What We Look For
- **Correctness**: Code compiles and runs correctly
- **Educational Value**: Changes enhance rather than diminish learning
- **Code Quality**: Clean, readable, well-documented code
- **Compatibility**: Works across common development environments
- **Testing**: Adequate testing of new functionality

### Review Timeline
- **Initial Review**: Within 1-2 weeks
- **Feedback**: Constructive feedback provided for improvements
- **Final Review**: After addressing feedback, typically 3-5 days

## 🏆 Recognition

Contributors will be acknowledged in:
- Repository contributor list
- Relevant documentation updates
- Course materials (where appropriate)

## 📞 Getting Help

### Questions or Issues
- **Documentation**: Check README files and code comments first
- **Issues**: Open an issue for bugs or enhancement requests
- **Discussions**: Use discussions for general questions
- **Email**: Contact maintainers for sensitive issues

### Common Issues
- **Build Failures**: Check compiler version and dependencies
- **Threading Issues**: Ensure pthread library is available
- **Platform Issues**: Note your OS and compiler version in reports

## 🎓 Learning Resources

### For Contributors
- [C11 Standard Reference](https://en.cppreference.com/w/c)
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [Git Best Practices](https://git-scm.com/book)

### Systems Programming Concepts
- Operating Systems Concepts (Silberschatz)
- The C Programming Language (Kernighan & Ritchie)
- Advanced Programming in the UNIX Environment (Stevens)

---

## 📄 Code of Conduct

### Our Standards
- **Respectful**: Be respectful and inclusive in all interactions
- **Educational**: Focus on enhancing learning for everyone
- **Constructive**: Provide helpful, actionable feedback
- **Academic Integrity**: Respect educational goals and academic honesty

### Enforcement
Project maintainers reserve the right to:
- Remove comments or contributions that don't align with educational goals
- Temporarily or permanently ban contributors who violate standards
- Make final decisions on contribution acceptance

---

*Thank you for helping make this educational resource better for everyone! Your contributions help current and future students learn fundamental systems programming concepts.*
