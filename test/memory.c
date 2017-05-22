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

static int cursor_pos = 0;

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
		pos = pos->next;
	}
	if (pos->free) {
		char *data_addr = &pos + sizeof(s_block);
		pos->free = 0;
		pos->size = size;
		return data_addr;
	} else {
		//Create a new
		s_block *metadata = pos + pos->size;
		metadata->free = 0;
		metadata->next = NULL;
		metadata->size = size;
		pos->next = metadata;
		return metadata + sizeof(s_block);
	}
}

int memfree(char* ptr)
{
	char *addr = ptr - sizeof(s_block);
	s_block *metadata = addr;
	metadata->free = 1;
}

char* memrealloc(char* ptr, size_t add)
{

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