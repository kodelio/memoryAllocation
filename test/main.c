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
	ptr[1] = 'a';
	ptr[2] = 'a';
	ptr[3] = 'a';
	ptr[3] = 'a';
	ptr[4] = 'a';
	ptr[5] = 'a';
	ptr[6] = 'a';
	ptr[7] = 'a';
	ptr[8] = 'a';
	ptr[9] = '\0';

	other_ptr[0] = 'b';
	other_ptr[1] = 'b';
	other_ptr[2] = 'b';
	other_ptr[3] = 'b';
	other_ptr[3] = 'b';
	other_ptr[4] = 'b';
	other_ptr[5] = 'b';
	other_ptr[6] = 'b';
	other_ptr[7] = 'b';
	other_ptr[8] = 'b';
	other_ptr[9] = '\0';

	third_ptr[0] = 'c';
	third_ptr[1] = 'c';
	third_ptr[2] = 'c';
	third_ptr[3] = 'c';
	third_ptr[3] = 'c';
	third_ptr[4] = 'c';
	third_ptr[5] = 'c';
	third_ptr[6] = 'c';
	third_ptr[7] = 'c';
	third_ptr[8] = 'c';
	third_ptr[9] = '\0';


	printf("First %s - second %s - third %s\n", ptr, other_ptr, third_ptr);
	memfree(ptr);
	return(EXIT_SUCCESS);
}

