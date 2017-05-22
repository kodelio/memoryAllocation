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
#include "memory.h"

/*
 * 
 */
int main(int argc, char** argv)
{
	char *ptr = memloc(sizeof(char) * 10);
	char *other_ptr = memloc(sizeof(char) * 10);
	char *third_ptr = memloc(sizeof(char) * 10);
	ptr[0] = 'a';
	ptr[1] = '\0';

	other_ptr[0] = 'b';
	other_ptr[1] = 'b';
	other_ptr[2] = '\0';

	third_ptr[0] = 'c';
	third_ptr[1] = 'c';
	third_ptr[2] = 'c';
	third_ptr[3] = 'c';
	third_ptr[3] = '\0';


	printf("First %p - second %p - third %p\n", ptr, other_ptr, third_ptr);
	memfree(ptr);
	ptr = memloc(sizeof(char) * 10);
	printf("After calloc : %p\n", ptr);

	return(EXIT_SUCCESS);
}

