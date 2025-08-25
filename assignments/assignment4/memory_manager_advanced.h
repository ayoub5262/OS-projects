#ifndef MEMORY_MANAGER_ADVANCED_H
#define MEMORY_MANAGER_ADVANCED_H

#include "memory_allocator_next_fit.h"
#include <stdlib.h> /* for size_t  */

void *bf_alloc(size_t size);
void bf_free(void *addr);

#endif
