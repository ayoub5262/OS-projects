#include "memory_allocator_first_fit.h"
#include <stdio.h>

size_t last_alloc = 0; // Use this variable to keep track of the last allocation.

/*
 * Note: Implement a helper function that finds a free gap with the appropriate size:
 */
static size_t find_gap(size_t req_size) {
	size_t i = last_alloc;
    size_t count = 0;

    // Traverse the allocation_list starting from last_alloc
    while (count < NUM_CHUNKS) {
        // If we find a free block with sufficient size
        if (allocation_list[i].status == CHUNK_FREE && allocation_list[i].length >= req_size)
            return i;

        // Move to the next block, wrap around if necessary
        i = (i + 1) % NUM_CHUNKS;
        count++;
    }
	return NUM_CHUNKS;
}



void *nf_alloc(size_t size) {
	// Is the value of size reasonable?
	if (size == 0) return NULL;

	size = size_to_chunks(size);
	size_t chunk_index = find_gap(size);

	// No suitable block found
	if (chunk_index == NUM_CHUNKS) return NULL;

	// Perform allocation
    allocation_list[chunk_index].status = CHUNK_ALLOCATED;
    size_t remaining = allocation_list[chunk_index].length - size;
    allocation_list[chunk_index].length = size;

    if (remaining > 0) {
        allocation_list[chunk_index + size].status = CHUNK_FREE;
        allocation_list[chunk_index + size].length = remaining;
    }

	last_alloc = chunk_index;

	return heap + chunk_index * CHUNK_SIZE;
}
