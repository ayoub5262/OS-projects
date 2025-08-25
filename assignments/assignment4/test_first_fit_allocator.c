#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "memory_allocator_first_fit.h"

int main(void)
{
	void *addr[16];
	int i = 0;

	char *foo = nf_alloc(10);
	*foo = 'c';

	printf("Current (empty) memory layout:\n");
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

	return 0;
}
