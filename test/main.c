/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: azarias
 *
 * Created on 22 mai 2017, 14:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

/*
 * 
 */
int main(int argc, char** argv)
{
	char *ptr = memloc(sizeof(char) * 10);
	char *other_ptr = memloc(sizeof(char) * 10);
	char *third_ptr = memloc(sizeof(char) * 10);
	memcpy(ptr, "1oucou", 7);
	memcpy(other_ptr, "2oucou", 7);
	memcpy(third_ptr, "3oucou", 7);


	printf("First %s - second %s - third %s\n", ptr, other_ptr, third_ptr);
	memfree(ptr);
	ptr = memcalloc(sizeof(char) * 10);
	printf("After calloc : %s\n", ptr);
	other_ptr = memrealloc(other_ptr, sizeof(char) * 5);
	printf("Realloc : %s\n", other_ptr);

	return(EXIT_SUCCESS);
}

