#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memory_allocator_best_fit.h"
#include "memory_manager_advanced.h"

#define soft_assert(expr) \
	if (!(expr)) { \
		printf("%s:%d: Assertion %s failed\n", __FILE__, __LINE__, #expr); \
	}

int main(void)
{
	char *addr[16];
	int i = 0;

	printf("Current (empty) memory layout:\n");
	dump_memory();
	
	printf("Allocate  10 KiB -> %p\n", addr[i] = bf_alloc( 10 * 1024));
	*addr[i] = 'A';
	i++;
	dump_memory();
	
	printf("Allocate  10 KiB -> %p\n", addr[i] = bf_alloc( 10 * 1024));
	*(addr[i]) = 'A';
	i++;
	dump_memory();
	
	printf("Allocate  8 KiB -> %p\n", addr[i] = bf_alloc( 8 * 1024));
	*(addr[i]) = 'A';
	i++;
	dump_memory();
	
	printf("Allocate  20 KiB -> %p\n", addr[i] = bf_alloc( 20 * 1024));
	*(addr[i]) = 'A';
	i++;
	dump_memory();
	
	printf("Free %p (10 KiB)\n", addr[0]);	
	bf_free(addr[0]);
	*addr[0] = 'F';
	dump_memory();
	
	printf("Free %p (8 KiB)\n", addr[2]);	
	bf_free(addr[2]);
	*addr[2] = 'F';
	dump_memory();
	
	printf("Allocate  20 KiB -> %p\n", addr[i] = bf_alloc( 20 * 1024));
	*(addr[i]) = 'A';
	i++;
	dump_memory();
	
	printf("Allocate 500 KiB -> %p\n", addr[i++] = bf_alloc( 500 * 1024));
	
	printf("Allocate  15 KiB -> %p\n", addr[i] = bf_alloc( 15 * 1024));
	*addr[i] = 'A';
	i++;
	dump_memory();
	
	printf("Free %p (20 KiB)\n", addr[4]);	
	bf_free(addr[4]);
	*addr[4] = 'F';
	dump_memory();
	
	printf("Allocate  6 KiB -> %p\n", addr[i] = bf_alloc( 6 * 1024));
	*addr[i] = 'A';
	i++;
	dump_memory();
	
	printf("Allocate 0 B -> %p\n", addr[i] = bf_alloc( 0 ));
	
	return 0;
}
