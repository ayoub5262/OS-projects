# =============================================================================
# Assignment 3: Process Synchronization & Threading
# =============================================================================

# Compiler and flags
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -g
THREAD_FLAGS := -pthread
POSIX_FLAGS := -D_POSIX_C_SOURCE=200112L
ALL_FLAGS := $(CFLAGS) $(THREAD_FLAGS) $(POSIX_FLAGS)

# Source files
FRAMEWORK_SRC := exam_grading_framework.c
FRAMEWORK_HDR := exam_grading_framework.h
FRAMEWORK_OBJ := exam_grading_framework.o

# Target executables
TARGETS := semaphore_basic_sync semaphore_advanced_patterns multithread_exam_system

# Color output
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m

# =============================================================================
# PHONY TARGETS
# =============================================================================

.PHONY: all clean semaphore_basic semaphore_advanced multithread_exam help test

# =============================================================================
# MAIN TARGETS
# =============================================================================

all: $(TARGETS)
	@echo "$(GREEN)✅ Assignment 3 - All targets built successfully!$(NC)"

# Convenience aliases
semaphore_basic: semaphore_basic_sync
semaphore_advanced: semaphore_advanced_patterns  
multithread_exam: multithread_exam_system

# =============================================================================
# EXECUTABLE TARGETS
# =============================================================================

semaphore_basic_sync: $(FRAMEWORK_OBJ) semaphore_basic_synchronization.o
	@echo "$(YELLOW)🔧 Building semaphore_basic_sync...$(NC)"
	$(CC) $(ALL_FLAGS) -o $@ $^

semaphore_advanced_patterns: $(FRAMEWORK_OBJ) semaphore_advanced_patterns.o
	@echo "$(YELLOW)🔧 Building semaphore_advanced_patterns...$(NC)"
	$(CC) $(ALL_FLAGS) -o $@ $^

multithread_exam_system: $(FRAMEWORK_OBJ) multithread_exam_system.o
	@echo "$(YELLOW)🔧 Building multithread_exam_system...$(NC)"
	$(CC) $(ALL_FLAGS) -o $@ $^

# =============================================================================
# OBJECT FILE RULES
# =============================================================================

%.o: %.c $(FRAMEWORK_HDR)
	@echo "$(YELLOW)📝 Compiling $<...$(NC)"
	$(CC) $(ALL_FLAGS) -c -o $@ $<

# =============================================================================
# TESTING TARGETS
# =============================================================================

test: all
	@echo "$(YELLOW)🧪 Running Assignment 3 programs...$(NC)"
	@echo "$(GREEN)Note: These are interactive programs. Run manually for full testing.$(NC)"
	@echo "Available executables:"
	@ls -la $(TARGETS) 2>/dev/null || echo "No executables found"

# =============================================================================
# CLEANUP
# =============================================================================

clean:
	@echo "$(YELLOW)🧹 Cleaning Assignment 3 build artifacts...$(NC)"
	rm -f *.o $(TARGETS)
	@echo "$(GREEN)✅ Clean completed!$(NC)"

# =============================================================================
# HELP
# =============================================================================

help:
	@echo "Assignment 3: Process Synchronization & Threading"
	@echo "================================================="
	@echo ""
	@echo "Available targets:"
	@echo "  all                       - Build all programs"
	@echo "  semaphore_basic_sync      - Basic semaphore synchronization"
	@echo "  semaphore_advanced_patterns - Advanced synchronization patterns"
	@echo "  multithread_exam_system   - Multi-threaded exam system"
	@echo "  test                      - List built programs"
	@echo "  clean                     - Remove all build artifacts"
	@echo "  help                      - Show this help"
	@echo ""
	@echo "Shortcuts:"
	@echo "  semaphore_basic           - Same as semaphore_basic_sync"
	@echo "  semaphore_advanced        - Same as semaphore_advanced_patterns"
	@echo "  multithread_exam          - Same as multithread_exam_system"
