/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   memory.h
 * Author: azarias
 *
 * Created on 22 mai 2017, 15:10
 */

#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	void memcp(char *dest, char *src, size_t n);

	char *memloc(size_t size);

	int memfree(char *ptr);

	char *memrealloc(char *ptr, size_t add);

	char *memcalloc(size_t size);

	int memsafefree(char *ptr);

#ifdef __cplusplus
}
#endif

#endif /* MEMORY_H */

