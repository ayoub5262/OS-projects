#ifndef MEMORY_ALLOCATOR_FIRST_FIT_H
#define MEMORY_ALLOCATOR_FIRST_FIT_H

#include "memory_allocator_next_fit.h"
#include <stdlib.h> /* size_t */

void *nf_alloc(size_t size);

#endif
