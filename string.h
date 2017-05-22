/* 
 * File:   string.h
 * Author: azarias
 *
 * Created on 29 avril 2017, 10:21
 */

#ifndef STRING_H
#define STRING_H

#include "types.h"


int strlen(const char *message);

char* itos(uint32_t val);

char* itox(uint32_t val, uint8_t bytes_number);

char downcase(char c);

char upcase(char c);

#endif /* STRING_H */

