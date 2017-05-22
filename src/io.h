/* 
 * File:   io.h
 * Author: azarias
 *
 * Created on 29 avril 2017, 10:25
 */
#ifndef IO_H
#define IO_H

#include "types.h"

#define SCREEN_START 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define SCREEN_CELLS SCREEN_HEIGHT * SCREEN_WIDTH


typedef struct{
    uint8_t print;
    uint8_t attribute;
} screen_print_t ;

extern uint8_t *video;
extern screen_print_t* video_map;
extern uint32_t cursor;


void print(const char *message, ...);

void put(char c);

void fill(const char filler);

void line_shift();

void clear();

#endif /* IO_H */

