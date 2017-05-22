/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "memory.h"

#define HEAP_SIZE 1064

char heap[HEAP_SIZE];

typedef struct s_block s_block;

struct s_block {
	size_t size;
	s_block *next;
	int free;
};

s_block *start = NULL;

void memcpy(char *dest, char *src, size_t n)
{
	int steps = n / sizeof(char);
	for (int i = 0; i < steps; i++) {
		dest[i] = src[i];
	}
}

char *memloc(size_t size)
{
	if (start == NULL) {
		start = &heap[0];
		start->free = 1;
		start->next = NULL;
		start->size = 0;
	}

	s_block *pos = start;
	while (pos->next != NULL) {
		if (pos->size == size && pos->free) {
			break;
		}
		pos = pos->next;
	}
	if (pos->free) {
		pos->free = 0;
		pos->size = size;
		return pos + 1;
	} else {
		//Create a new
		s_block *metadata = pos + pos->size;
		metadata->free = 0;
		metadata->next = NULL;
		metadata->size = size;
		pos->next = metadata;
		return metadata + 1;
	}
}

int memfree(char* ptr)
{
	s_block *metadata = ptr - sizeof(s_block);
	metadata->free = 1;
	return 0;
}

char* memrealloc(char* ptr, size_t add)
{
	s_block *metadata = ptr - sizeof(s_block);
	int block_size = metadata->size;
	char *nw_addr = memloc(block_size + add);
	memcpy(nw_addr, ptr, block_size);
	memfree(ptr);
	return nw_addr;
}

char *memcalloc(size_t size)
{
	char *address = memloc(size);
	int steps = size / sizeof(char);
	for (int i = 0; i < steps; i++) {
		address[i] = 0;
	}
	return address;
}