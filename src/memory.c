/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "memory.h"

#define HEAP_SIZE 1024

char heap[1];

typedef struct s_block s_block;

struct s_block {
	size_t size;
	s_block *next;
	int free;
};

s_block *start = NULL;

void memcp(char *dest, char *src, size_t n)
{
	int steps = n / sizeof(char);
	for (int i = 0; i < steps; i++) {
		dest[i] = src[i];
	}
}

char *memloc(size_t size)
{
	if (start == NULL) {
		start = (s_block*) 0x1024;
		start->free = 1;
		start->next = NULL;
		start->size = 0;
	}

	s_block *pos = start;
	while (pos->next != NULL) {
		if (size <= pos->size && pos->free) {
			break;
		}
		void *unitCurr = (void*) pos;
		void *startCurr = (void*) start;

		int diff = (unitCurr - startCurr);
		if (diff > HEAP_SIZE) {//If gone too far => no more place
			return NULL;
		}
		pos = pos->next;
	}
	if (pos->free) {
		pos->free = 0;
		pos->size = size;
		return(char*) (pos + 1);
	} else {
		//Create a new block
		void *nwptr = (void*) (pos + 1);
		s_block *metadata = (s_block*) (nwptr + pos->size);
		metadata->free = 0;
		metadata->next = NULL;
		metadata->size = size;
		pos->next = metadata;
		return(char*) (metadata + 1);
	}
}

int memfree(char* ptr)
{
	s_block *metadata = (s_block*) (ptr - sizeof(s_block));
	metadata->free = 1;

	return 0;
}

int memsafefree(char *ptr)
{
	s_block *metadata = (s_block*) (ptr - sizeof(s_block));
	for (int i = 0; i < metadata->size; i++) {
		ptr[i] = 0;
	}
	metadata->free = 1;

	return 0;
}

char* memrealloc(char* ptr, size_t add)
{
	s_block *metadata = (s_block*) (ptr - sizeof(s_block));
	size_t block_size = metadata->size;
	char *nw_addr = memloc(block_size + add);
	if (nw_addr == NULL) {
		return NULL; //can't reallocate
	}
	memcp(nw_addr, ptr, block_size);
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