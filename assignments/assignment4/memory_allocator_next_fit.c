#include <stdio.h>
#include <string.h>

#include "memory_allocator_next_fit.h"

// The main memory heap
char heap[CHUNK_SIZE * NUM_CHUNKS];

/*
 * The allocation list indicates for the first chunk of each contiguous
 * memory region how large it is (i.e., how many chunks it comprises)
 * and whether it is reserved or free. Initially, the entire
 * memory is free.
 */
mem_info allocation_list[NUM_CHUNKS] = {{CHUNK_FREE, NUM_CHUNKS}};

size_t size_to_chunks(size_t bytes)
{
	if ((bytes % CHUNK_SIZE) != 0)
		return bytes / CHUNK_SIZE + 1;
	return bytes / CHUNK_SIZE;
}

void dump_memory()
{
	size_t in_range = 0;
	size_t free_chunks = 0;
	unsigned char status = 0;
	putchar('|');
	for (size_t i = 0; i < NUM_CHUNKS; i++) {
		if (allocation_list[i].status > 1) {
			printf("\n [!] Consistency error in memory management: "
					"allocation_list[%zu].status == %d != 0/1\n", i, allocation_list[i].status);
			exit(EXIT_FAILURE);
		}
		if (in_range && allocation_list[i].length) {
			printf("\n [!] Consistency error in memory management: "
					"allocation_list[%zu].length == %zu != 0\n", i, allocation_list[i].length);
			exit(EXIT_FAILURE);
		}
		if (allocation_list[i].length) {
			if (i > 0 && status == CHUNK_FREE && status == allocation_list[i].status) {
				printf("\n [!] Consistency error in memory management: "
						"allocation_list[%zu] is free and was not merged with the "
						"previous (also free) memory region\n", i);
			}
			status = allocation_list[i].status;
			in_range = allocation_list[i].length;
		} else if (!in_range) {
			printf("\n [!] Consistency error in memory management: "
					"allocation_list[%zu].length == 0, but a new region must start here\n", i);
			exit(EXIT_FAILURE);
		}
		if (status == CHUNK_ALLOCATED) {
			putchar('#');
		} else {
			putchar('.');
			free_chunks++;
		}
		in_range--;
	}
	putchar('|');
	printf(" (%3zu KiB free)\n", free_chunks * 4);
}
