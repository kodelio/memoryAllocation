

/* 
 * File:   keyboard.h
 * Author: azarias
 *
 * Created on 29 avril 2017, 15:08
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"
#include "string.h"


//Keyboard mapping
typedef struct {
    char normal;
    char maj;
} key_t;


#define KEYBOARD_MAP_SIZE 100

#define K_MAP set_char


key_t keyboard_map[KEYBOARD_MAP_SIZE];


extern int maj_pressed;

extern int altgr_pressed;

void map_keyboard();

char get_char(int keycode);

void set_char(char normal, char maj, uint16_t index);

#endif /* KEYBOARD_H */

