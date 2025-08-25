#include "memory_allocator_best_fit.h"
#include <stdio.h>

extern size_t last_alloc;

void nf_free(void *addr) {
	// Is the address addr reasonable?
	if (addr == NULL) return;

	size_t chunk_index = ((char*)addr - heap) / CHUNK_SIZE;

	if (chunk_index >= NUM_CHUNKS || allocation_list[chunk_index].status != CHUNK_ALLOCATED) {
        perror("Invalid free address\n");
        exit(255);
    }
	// Free memory
	allocation_list[chunk_index].status = CHUNK_FREE;
    size_t old_size = allocation_list[chunk_index].length;

	// Merge subsequent free blocks
    size_t next_index = chunk_index + old_size;
    if (next_index < NUM_CHUNKS && allocation_list[next_index].status == CHUNK_FREE) {
        allocation_list[chunk_index].length += allocation_list[next_index].length;
        allocation_list[next_index].length = 0;
    }
    // Merge previous free blocks
    size_t prev_index = chunk_index;
    while (prev_index > 0 && allocation_list[prev_index - 1].status == CHUNK_FREE)
        prev_index--;

    if (prev_index < chunk_index) {
        allocation_list[prev_index].length += allocation_list[chunk_index].length;
        allocation_list[chunk_index].length = 0;
    }
    // Adjust the last allocation point if it now lies within a free block
    if (last_alloc >= chunk_index && last_alloc < chunk_index + old_size)
        last_alloc = prev_index;

}
