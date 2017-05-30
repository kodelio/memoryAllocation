
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
	memcp(ptr, "1oucou", 7);
	memcp(other_ptr, "2oucou", 7);
	memcp(third_ptr, "3oucou", 7);


	printf("First %p - second %p - third %p - diff1 %d\n", ptr, other_ptr, third_ptr, other_ptr - ptr);
	memfree(ptr);
	ptr = memcalloc(sizeof(char) * 10);
	printf("After calloc : %p\n", ptr);
	other_ptr = memrealloc(other_ptr, sizeof(char) * 5);
	printf("Realloc : %s\n", other_ptr);

	char *test = memloc(1);
	test[0] = '\0';
	char *dest = "Un message tres tres long, le plus long possible pour tester la capaciter du malloc,";
	int ln = strlen(dest);
	for (int i = 0; i < ln; i++) {
		printf("Need to allocate %zu\n", strlen(test) + 2);
		char *tmp = memrealloc(test, strlen(test) + 2);
		if (tmp == NULL) {
			printf("Impossible, taille maximale atteinte\n");
			break;
		} else {
			test = tmp;
			test[i] = dest[i];
			test[i + 1] = '\0';
			printf("%p = %s\n", test, test);
		}
	}

	return(EXIT_SUCCESS);
}

