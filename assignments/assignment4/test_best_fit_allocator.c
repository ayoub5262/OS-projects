#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "memory_allocator_best_fit.h"

int main(void)
{
	void *addr[16];
	int i = 0;

	printf("Current (empty) memory layout:\n");
	dump_memory();
	printf("Allocate  10 KiB -> %p\n", addr[i++] = nf_alloc( 10 * 1024));
	dump_memory();
	printf("Free %p (10 KiB)\n", addr[0]);
	nf_free(addr[0]);
	dump_memory();
	printf("Allocate  10 KiB -> %p\n", addr[i++] = nf_alloc( 10 * 1024));
	dump_memory();
	printf("Allocate  10 KiB -> %p\n", addr[i++] = nf_alloc( 10 * 1024));
	dump_memory();
	printf("Free %p (10 KiB)\n", addr[1]);
	nf_free(addr[1]);
	dump_memory();
	printf("Allocate  5 KiB -> %p\n", addr[i++] = nf_alloc( 5 * 1024));
	dump_memory();
	printf("Free %p (10 KiB)\n", addr[2]);
	nf_free(addr[2]);
	dump_memory();
	printf("Free %p (5 KiB)\n", addr[3]);
	nf_free(addr[3]);
	dump_memory();
	printf("Allocate  10 KiB -> %p\n", addr[i++] = nf_alloc( 10 * 1024));
	dump_memory();
	printf("Allocate 500 KiB -> %p\n", addr[i++] = nf_alloc(944 * 1024));
	dump_memory();
	printf("Allocate   1   B -> %p\n", addr[i++] = nf_alloc(1));
	dump_memory();
	printf("Allocate 200 KiB -> %p\n", addr[i++] = nf_alloc(200 * 1024));
	dump_memory();
	printf("Allocate  40 KiB -> %p\n", addr[i++] = nf_alloc( 40 * 1024));
	dump_memory();
	printf("Allocate   1   B -> %p\n", addr[i++] = nf_alloc(1));
	dump_memory();
	printf("Free %p (200 KiB)\n", addr[7]);
	nf_free(addr[7]);
	dump_memory();
	printf("Free NULL\n");
	nf_free(NULL);
	dump_memory();
	printf("Allocate  20 KiB -> %p\n", addr[i++] = nf_alloc( 20 * 1024));
	dump_memory();

	return 0;
}
