/* 
 * File:   string.h
 * Author: azarias
 *
 * Created on 29 avril 2017, 10:21
 */

#define MAX_TMP_STR_SIZE 32

char temp_str[MAX_TMP_STR_SIZE];

#include "string.h"

int strlen(const char *message)
{
	return(*message) ? strlen(message + 1) + 1 : 0;
}

char* itos(uint32_t val)
{
	uint8_t left_byte;
	int16_t l_index = MAX_TMP_STR_SIZE - 2;
	uint8_t left_digit = 0;
	temp_str[MAX_TMP_STR_SIZE - 1] = 0;

	do {
		left_byte = val % 10;
		temp_str[l_index] = left_byte + '0';
		val /= 10;
		l_index--;
	} while (val != 0);

	return(temp_str + l_index + 1);
}

char* itox(uint32_t val, uint8_t bytes_number)
{
	uint8_t l_byte;
	uint8_t l_index = 0;
	uint8_t l_digit = (bytes_number << 1);

	if (bytes_number > 0 && bytes_number < 4) {
		l_byte = val & 0x0000000F;
		if (l_byte < 10)
			temp_str[l_digit - l_index - 1] = l_byte + '0';
		else
			temp_str[l_digit - l_index - 1] = l_byte - 10 + 'A';

		l_index++;
		val >>= 4;
	} else {
		temp_str[0] = 0;
	}

	return temp_str;
}

char upcase(char c)
{
	if(c >= 'a' && c <= 'z'){
		return c-' ';
	}
	return c;
}

char downcase(char c)
{
	if(c >= 'A' && c <= 'Z')
		return c+' ';
	return c;
}