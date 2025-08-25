#ifndef MEMORY_ALLOCATOR_NEXT_FIT_H
#define MEMORY_ALLOCATOR_NEXT_FIT_H

#include <stdlib.h> /* for size_t */

#define CHUNK_SIZE 4096
#define NUM_CHUNKS 64

#define CHUNK_FREE 0
#define CHUNK_ALLOCATED 1

/*
 * Information about a contiguous memory region.
 * If length == 0, no memory region starts here and the status value
 * is irrelevant. Otherwise, length specifies the length in blocks (chunks) and
 * status determines whether it is a free (CHUNK_FREE) or allocated
 * (CHUNK_ALLOCATED) memory region.
 */
typedef struct {
	unsigned char status;
	size_t length;
} mem_info;

extern char heap[CHUNK_SIZE * NUM_CHUNKS];
extern mem_info allocation_list[NUM_CHUNKS];

size_t size_to_chunks(size_t bytes);
void dump_memory();

#endif
