# =============================================================================
# Assignment 4: Memory Management Algorithms
# =============================================================================

# Compiler and flags
CC ?= gcc
CFLAGS := -Wall -Wextra -std=c11 -g
OPTFLAGS := -O2
DEBUG_FLAGS := -DDEBUG -g3
LDFLAGS := 

# Color output
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m

# Source files and headers
ALLOCATOR_SOURCES := memory_allocator_first_fit.c memory_allocator_best_fit.c memory_allocator_next_fit.c
MANAGER_SOURCES := memory_manager_advanced.c
TEST_SOURCES := test_first_fit_allocator.c test_best_fit_allocator.c test_advanced_memory_manager.c

# All source files
SOURCES := $(ALLOCATOR_SOURCES) $(MANAGER_SOURCES) $(TEST_SOURCES)
OBJECTS := $(SOURCES:.c=.o)
HEADERS := $(wildcard *.h)

# Test executables
TEST_TARGETS := test_first_fit test_best_fit test_advanced

# =============================================================================
# PHONY TARGETS
# =============================================================================

.PHONY: all clean test help first_fit best_fit advanced debug release

# =============================================================================
# MAIN TARGETS
# =============================================================================

all: $(OBJECTS) $(TEST_TARGETS)
	@echo "$(GREEN)✅ Assignment 4 - All targets built successfully!$(NC)"

# Include dependency file if it exists
-include deps.mk

# =============================================================================
# TEST EXECUTABLE TARGETS
# =============================================================================

test_first_fit: test_first_fit_allocator.o memory_allocator_first_fit.o memory_allocator_next_fit.o
	@echo "$(YELLOW)🔧 Building first-fit allocator test...$(NC)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

test_best_fit: test_best_fit_allocator.o memory_allocator_best_fit.o memory_allocator_first_fit.o memory_allocator_next_fit.o
	@echo "$(YELLOW)🔧 Building best-fit allocator test...$(NC)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

test_advanced: test_advanced_memory_manager.o memory_manager_advanced.o memory_allocator_next_fit.o
	@echo "$(YELLOW)🔧 Building advanced memory manager test...$(NC)"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# =============================================================================
# OBJECT FILE RULES
# =============================================================================

%.o: %.c $(HEADERS)
	@echo "$(YELLOW)📝 Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c -o $@ $<

# =============================================================================
# TESTING TARGETS
# =============================================================================

test: $(TEST_TARGETS)
	@echo "$(BLUE)🧪 Running memory management tests...$(NC)"

first_fit: test_first_fit
	@echo "$(BLUE)🧪 Running first-fit allocator tests...$(NC)"
	./test_first_fit

best_fit: test_best_fit
	@echo "$(BLUE)🧪 Running best-fit allocator tests...$(NC)"
	./test_best_fit

advanced: test_advanced
	@echo "$(BLUE)🧪 Running advanced memory manager tests...$(NC)"
	./test_advanced

# Run all tests
test-all: first_fit best_fit advanced
	@echo "$(GREEN)✅ All memory management tests completed!$(NC)"

# =============================================================================
# BUILD VARIANTS
# =============================================================================

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all
	@echo "$(GREEN)🐛 Debug build completed!$(NC)"

release: CFLAGS += $(OPTFLAGS) -DNDEBUG
release: clean all
	@echo "$(GREEN)🚀 Release build completed!$(NC)"

# =============================================================================
# DEPENDENCY GENERATION
# =============================================================================

deps: deps.mk

deps.mk: $(SOURCES) $(HEADERS)
	@echo "$(YELLOW)📋 Generating dependency file...$(NC)"
	$(CC) -MM $(SOURCES) > deps.mk

# =============================================================================
# ANALYSIS AND PROFILING
# =============================================================================

analyze: $(SOURCES)
	@echo "$(BLUE)🔍 Running static analysis...$(NC)"
	@if command -v cppcheck >/dev/null 2>&1; then \
		cppcheck --enable=all --std=c11 $(SOURCES); \
	else \
		echo "$(YELLOW)⚠️  cppcheck not found, skipping static analysis$(NC)"; \
	fi

profile: CFLAGS += -pg
profile: clean all
	@echo "$(BLUE)📊 Profile-enabled build completed!$(NC)"
	@echo "Run tests and use 'gprof' to analyze performance"

# =============================================================================
# CLEANUP
# =============================================================================

clean:
	@echo "$(YELLOW)🧹 Cleaning Assignment 4 build artifacts...$(NC)"
	rm -f $(TEST_TARGETS) $(OBJECTS)
	@echo "$(GREEN)✅ Clean completed!$(NC)"

distclean: clean
	@echo "$(YELLOW)🗑️  Deep cleaning Assignment 4...$(NC)"
	rm -f deps.mk gmon.out *.gcda *.gcno *.gcov
	@echo "$(GREEN)🗑️  Deep clean completed!$(NC)"

# =============================================================================
# HELP
# =============================================================================

help:
	@echo "Assignment 4: Memory Management Algorithms"
	@echo "=========================================="
	@echo ""
	@echo "$(GREEN)🎯 MAIN TARGETS:$(NC)"
	@echo "  all              - Build all object files and test programs"
	@echo "  test             - Build test executables"
	@echo "  clean            - Remove build artifacts"
	@echo "  distclean        - Deep clean (including generated files)"
	@echo ""
	@echo "$(GREEN)🧪 TEST TARGETS:$(NC)"
	@echo "  test_first_fit   - Build first-fit allocator test"
	@echo "  test_best_fit    - Build best-fit allocator test"  
	@echo "  test_advanced    - Build advanced memory manager test"
	@echo "  first_fit        - Build and run first-fit tests"
	@echo "  best_fit         - Build and run best-fit tests"
	@echo "  advanced         - Build and run advanced tests"
	@echo "  test-all         - Run all tests sequentially"
	@echo ""
	@echo "$(GREEN)🔧 BUILD VARIANTS:$(NC)"
	@echo "  debug            - Build with debug symbols and debug flags"
	@echo "  release          - Build optimized release version"
	@echo "  profile          - Build with profiling support"
	@echo ""
	@echo "$(GREEN)🔍 ANALYSIS:$(NC)"
	@echo "  analyze          - Run static code analysis (requires cppcheck)"
	@echo "  deps             - Generate dependency file"
	@echo ""
	@echo "$(GREEN)📚 ALGORITHMS IMPLEMENTED:$(NC)"
	@echo "  • First-Fit:     Fast allocation, potential fragmentation"
	@echo "  • Best-Fit:      Optimal space usage, slower allocation"
	@echo "  • Next-Fit:      Balanced approach, good performance"
	@echo "  • Advanced:      Extended features and optimizations"
