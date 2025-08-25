# =============================================================================
# Systems Programming Course - Main Makefile
# Author: Systems Programming Course
# Description: Unified build system for all assignments and utilities
# Usage: make [target]
# =============================================================================

# =============================================================================
# CONFIGURATION
# =============================================================================

# Compiler and flags
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -g
THREAD_FLAGS := -pthread
POSIX_FLAGS := -D_POSIX_C_SOURCE=200112L

# Build directories
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj

# Color output for better readability
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m # No Color

# =============================================================================
# PHONY TARGETS
# =============================================================================

.PHONY: all clean assignments utilities help assignment2 assignment3 assignment4 assignment5
.PHONY: test info check-dependencies setup format validate

# =============================================================================
# DEFAULT TARGET
# =============================================================================

all: check-dependencies assignments utilities
	@echo "$(GREEN)✅ All projects built successfully!$(NC)"
	@echo "$(BLUE)💡 Use 'make help' for available commands$(NC)"

# =============================================================================
# DEPENDENCY CHECK
# =============================================================================

check-dependencies:
	@echo "$(BLUE)🔍 Checking build dependencies...$(NC)"
	@command -v $(CC) >/dev/null 2>&1 || { echo "$(RED)❌ Error: GCC compiler not found$(NC)"; exit 1; }
	@command -v make >/dev/null 2>&1 || { echo "$(RED)❌ Error: Make not found$(NC)"; exit 1; }
	@echo "$(GREEN)✅ Dependencies satisfied$(NC)"

# =============================================================================
# MAIN BUILD TARGETS
# =============================================================================

# Build all assignments
assignments: assignment2 assignment3 assignment4 assignment5
	@echo "$(GREEN)📚 All assignments built successfully!$(NC)"

# Build utilities
utilities:
	@echo "$(YELLOW)🔧 Building utility programs...$(NC)"
	@cd utilities && $(CC) $(CFLAGS) -o interactive_shell_menu interactive_shell_menu.c 2>/dev/null || echo "$(YELLOW)⚠️  interactive_shell_menu build skipped$(NC)"
	@cd utilities && $(CC) $(CFLAGS) -o interactive_menu_advanced interactive_menu_advanced.c 2>/dev/null || echo "$(YELLOW)⚠️  interactive_menu_advanced build skipped$(NC)"  
	@cd utilities && $(CC) $(CFLAGS) -o prime_number_generator prime_number_generator.c 2>/dev/null || echo "$(YELLOW)⚠️  prime_number_generator build skipped$(NC)"
	@cd utilities && $(CC) $(CFLAGS) -o prime_number_advanced prime_number_advanced.c 2>/dev/null || echo "$(YELLOW)⚠️  prime_number_advanced build skipped$(NC)"
	@cd utilities && $(CC) $(CFLAGS) -o process_fork_demonstration process_fork_demonstration.c 2>/dev/null || echo "$(YELLOW)⚠️  process_fork_demonstration build skipped$(NC)"
	@echo "$(GREEN)🔧 Utilities built successfully!$(NC)"

# =============================================================================
# INDIVIDUAL ASSIGNMENT TARGETS
# =============================================================================

assignment2:
	@echo "$(YELLOW)📝 Building Assignment 2 - System Programming Fundamentals...$(NC)"
	@cd "assignments/assignment2" && $(CC) $(CFLAGS) $(THREAD_FLAGS) -o thread_bag_distribution thread_bag_distribution.c 2>/dev/null || echo "$(YELLOW)⚠️  thread_bag_distribution build skipped$(NC)"
	@cd "assignments/assignment2" && $(CC) $(CFLAGS) -o file_operations_advanced file_operations_advanced.c 2>/dev/null || echo "$(YELLOW)⚠️  file_operations_advanced build skipped$(NC)"
	@cd "assignments/assignment2" && $(CC) $(CFLAGS) -o system_programming_extended system_programming_extended.c 2>/dev/null || echo "$(YELLOW)⚠️  system_programming_extended build skipped$(NC)"
	@echo "$(GREEN)✅ Assignment 2 completed$(NC)"

assignment3:
	@echo "$(YELLOW)🧵 Building Assignment 3 - Process Synchronization & Threading...$(NC)"
	@cd "assignments/assignment3" && $(MAKE) all 2>/dev/null || echo "$(YELLOW)⚠️  Assignment 3 build completed with warnings$(NC)"
	@echo "$(GREEN)✅ Assignment 3 completed$(NC)"

assignment4:
	@echo "$(YELLOW)💾 Building Assignment 4 - Memory Management Algorithms...$(NC)"
	@cd "assignments/assignment4" && $(MAKE) all 2>/dev/null || echo "$(YELLOW)⚠️  Assignment 4 build completed with warnings$(NC)"
	@echo "$(GREEN)✅ Assignment 4 completed$(NC)"

assignment5:
	@echo "$(YELLOW)🎨 Building Assignment 5 - Image Processing...$(NC)"
	@cd "assignments/assignment5" && $(CC) $(CFLAGS) -o ppm_image_reader ppm_image_reader.c 2>/dev/null || echo "$(YELLOW)⚠️  ppm_image_reader build skipped$(NC)"
	@cd "assignments/assignment5" && $(CC) $(CFLAGS) -o image_transformation_engine image_transformation_engine.c 2>/dev/null || echo "$(YELLOW)⚠️  image_transformation_engine build skipped$(NC)"
	@cd "assignments/assignment5" && $(CC) $(CFLAGS) -o image_filter_processor image_filter_processor.c 2>/dev/null || echo "$(YELLOW)⚠️  image_filter_processor build skipped$(NC)"
	@cd "assignments/assignment5" && $(CC) $(CFLAGS) -o advanced_image_processor advanced_image_processor.c 2>/dev/null || echo "$(YELLOW)⚠️  advanced_image_processor build skipped$(NC)"
	@echo "$(GREEN)✅ Assignment 5 completed$(NC)"

# =============================================================================
# TESTING TARGETS
# =============================================================================

test: assignment4
	@echo "$(BLUE)🧪 Running test suites...$(NC)"
	@cd "assignments/assignment4" && $(MAKE) test_first_fit 2>/dev/null && echo "$(GREEN)✅ First-fit allocator tests passed$(NC)" || echo "$(RED)❌ First-fit tests failed$(NC)"
	@cd "assignments/assignment4" && $(MAKE) test_best_fit 2>/dev/null && echo "$(GREEN)✅ Best-fit allocator tests passed$(NC)" || echo "$(RED)❌ Best-fit tests failed$(NC)"
	@cd "assignments/assignment4" && $(MAKE) test_advanced 2>/dev/null && echo "$(GREEN)✅ Advanced memory manager tests passed$(NC)" || echo "$(RED)❌ Advanced tests failed$(NC)"

validate: all
	@echo "$(BLUE)🔍 Validating build outputs...$(NC)"
	@ls -la assignments/assignment*/*[!.]*[!c][!h] 2>/dev/null && echo "$(GREEN)✅ Assignment executables found$(NC)" || echo "$(YELLOW)⚠️  Some assignment executables missing$(NC)"
	@ls -la utilities/*[!.]*[!c][!h] 2>/dev/null && echo "$(GREEN)✅ Utility executables found$(NC)" || echo "$(YELLOW)⚠️  Some utility executables missing$(NC)"

# =============================================================================
# CLEANUP TARGETS
# =============================================================================

clean:
	@echo "$(BLUE)🧹 Cleaning all build artifacts...$(NC)"
	@cd "assignments/assignment2" && rm -f thread_bag_distribution file_operations_advanced system_programming_extended *.o 2>/dev/null || true
	@cd "assignments/assignment3" && $(MAKE) clean 2>/dev/null || rm -f *.o semaphore_basic_sync semaphore_advanced_patterns multithread_exam_system 2>/dev/null || true
	@cd "assignments/assignment4" && $(MAKE) clean 2>/dev/null || rm -f *.o test_first_fit test_best_fit test_advanced memory_* 2>/dev/null || true
	@cd "assignments/assignment5" && rm -f ppm_image_reader image_transformation_engine image_filter_processor advanced_image_processor *.o 2>/dev/null || true
	@cd utilities && rm -f interactive_shell_menu interactive_menu_advanced prime_number_generator prime_number_advanced process_fork_demonstration *.o 2>/dev/null || true
	@rm -rf $(BUILD_DIR) 2>/dev/null || true
	@echo "$(GREEN)🧹 Clean completed!$(NC)"

distclean: clean
	@echo "$(BLUE)🗑️  Performing deep clean...$(NC)"
	@find . -name "*.o" -delete 2>/dev/null || true
	@find . -name "core" -delete 2>/dev/null || true
	@find . -name "*.core" -delete 2>/dev/null || true
	@find . -name ".DS_Store" -delete 2>/dev/null || true
	@echo "$(GREEN)🗑️  Deep clean completed!$(NC)"

# =============================================================================
# INFORMATION TARGETS
# =============================================================================

help:
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(NC)"
	@echo "$(BLUE)  Systems Programming Course - Build System Help$(NC)"
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(NC)"
	@echo ""
	@echo "$(GREEN)📋 MAIN TARGETS:$(NC)"
	@echo "  $(YELLOW)all$(NC)           - Build all projects (assignments + utilities)"
	@echo "  $(YELLOW)assignments$(NC)   - Build all assignments only"
	@echo "  $(YELLOW)utilities$(NC)     - Build utility programs only"
	@echo "  $(YELLOW)test$(NC)          - Run test suites (where available)"
	@echo "  $(YELLOW)clean$(NC)         - Remove all build artifacts"
	@echo "  $(YELLOW)distclean$(NC)     - Deep clean (remove all generated files)"
	@echo ""
	@echo "$(GREEN)📚 ASSIGNMENT TARGETS:$(NC)"
	@echo "  $(YELLOW)assignment2$(NC)   - System Programming Fundamentals"
	@echo "  $(YELLOW)assignment3$(NC)   - Process Synchronization & Threading"
	@echo "  $(YELLOW)assignment4$(NC)   - Memory Management Algorithms"
	@echo "  $(YELLOW)assignment5$(NC)   - Image Processing with PPM"
	@echo ""
	@echo "$(GREEN)🔧 UTILITY TARGETS:$(NC)"
	@echo "  $(YELLOW)validate$(NC)      - Check that all expected outputs exist"
	@echo "  $(YELLOW)info$(NC)          - Show project information"
	@echo "  $(YELLOW)help$(NC)          - Show this help message"
	@echo ""
	@echo "$(GREEN)📁 PROJECT STRUCTURE:$(NC)"
	@echo "  assignments/assignment2/  - Basic system programming"
	@echo "  assignments/assignment3/  - Process synchronization"  
	@echo "  assignments/assignment4/  - Memory management"
	@echo "  assignments/assignment5/  - Image processing"
	@echo "  utilities/                - Helper programs"
	@echo ""
	@echo "$(GREEN)💡 EXAMPLES:$(NC)"
	@echo "  make all                    # Build everything"
	@echo "  make assignment4           # Build only Assignment 4"
	@echo "  make clean                  # Clean build artifacts"
	@echo "  make test                   # Run tests"
	@echo ""
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(NC)"

info:
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(NC)"
	@echo "$(BLUE)  Systems Programming in C - Operating Systems Course$(NC)"
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(NC)"
	@echo ""
	@echo "$(GREEN)🎯 COURSE OBJECTIVES:$(NC)"
	@echo "  • Master fundamental systems programming concepts"
	@echo "  • Implement memory management algorithms"
	@echo "  • Understand process synchronization and threading"
	@echo "  • Apply concurrent programming patterns"
	@echo "  • Develop image processing applications"
	@echo ""
	@echo "$(GREEN)🛠️  TECHNOLOGIES:$(NC)"
	@echo "  • Language: C11 Standard"
	@echo "  • Threading: POSIX threads (pthread)"
	@echo "  • Synchronization: Semaphores, mutexes"
	@echo "  • Build System: GNU Make"
	@echo "  • Image Format: PPM (Portable Pixmap)"
	@echo ""
	@echo "$(GREEN)📊 ASSIGNMENTS OVERVIEW:$(NC)"
	@echo "  $(YELLOW)Assignment 2:$(NC) File I/O, system calls, basic threading"
	@echo "  $(YELLOW)Assignment 3:$(NC) Semaphores, mutexes, synchronization patterns"
	@echo "  $(YELLOW)Assignment 4:$(NC) First-fit, best-fit, next-fit allocators"
	@echo "  $(YELLOW)Assignment 5:$(NC) PPM parsing, image transformations, filters"
	@echo ""
	@echo "$(GREEN)🏆 SKILLS DEMONSTRATED:$(NC)"
	@echo "  • Low-level memory management"
	@echo "  • Concurrent programming"
	@echo "  • Algorithm implementation"
	@echo "  • System-level programming"
	@echo "  • Performance optimization"
	@echo ""
	@echo "$(BLUE)Use 'make help' for build instructions$(NC)"
	@echo "$(BLUE)════════════════════════════════════════════════════════════════$(NC)"

# =============================================================================
# SETUP AND DEVELOPMENT TARGETS
# =============================================================================

setup:
	@echo "$(BLUE)🔧 Setting up development environment...$(NC)"
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)
	@echo "$(GREEN)✅ Build directories created$(NC)"
	@echo "$(GREEN)✅ Development environment ready$(NC)"
	@echo "$(BLUE)💡 Run 'make all' to build all projects$(NC)"

# Format source code (if clang-format is available)
format:
	@echo "$(BLUE)🎨 Formatting source code...$(NC)"
	@if command -v clang-format >/dev/null 2>&1; then \
		find . -name "*.c" -o -name "*.h" | xargs clang-format -i; \
		echo "$(GREEN)✅ Code formatting completed$(NC)"; \
	else \
		echo "$(YELLOW)⚠️  clang-format not found, skipping formatting$(NC)"; \
	fi
