/* 
 * File:   io.h
 * Author: azarias
 *
 * Created on 29 avril 2017, 10:25
 */

#include "io.h"
#include "string.h"
#include "stdarg.h"

uint8_t *video = (uint8_t*) SCREEN_START;
uint32_t cursor = 0;
screen_print_t* video_map = (screen_print_t*) SCREEN_START;

void printf(const char *message, ...)
{
	va_list ap;
	va_start(ap, message);
	int len = strlen(message);
	for (int i = 0; i < len; i++) {
		if (message[i] == '\n') {
			//back to start + next line
			cursor = cursor - (cursor % SCREEN_WIDTH) - 1;
			cursor += SCREEN_WIDTH;
		} else if (message[i] == '\r') {//back to start
			cursor = cursor - (cursor % SCREEN_WIDTH) - 1;
		} else {
			if (message[i] == '%' && i < len - 1) {
				char t = message[++i];
				if(t == 'c'){
					char c = va_arg(ap, char);
					char str[2];
					str[0] = c;
					str[1] = 0;
					printf(str);
					cursor--;
				}else if(t == 's'){
					char *s = va_arg(ap, char*);
					printf(s);
				}else if(t == 'd'){
					uint32_t i = va_arg(ap, uint32_t);
					char *s = itos(i);
					printf(s);
				}
			} else {
				put(message[i]);
			}


		}
		cursor++;
		if (cursor >= SCREEN_CELLS)
			line_shift();
	}
	va_end(ap);
}

void put(char c){
	video_map[cursor].attribute = 0x07;
	video_map[cursor].print = c;
}

void line_shift()
{
	for (int y = 0; y < SCREEN_HEIGHT - 1; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			screen_print_t next = video_map[((y + 1) * SCREEN_WIDTH) + x];
			video_map[y * SCREEN_WIDTH + x].attribute = next.attribute;
			video_map[y * SCREEN_WIDTH + x].print = next.print;
		}
	}
	for (int x = 0; x < SCREEN_WIDTH; x++) {
		video_map[(SCREEN_HEIGHT - 1) * SCREEN_WIDTH + x].print = ' ';
		video_map[(SCREEN_HEIGHT - 1) * SCREEN_WIDTH + x].attribute = 0x07;
	}
	cursor -= SCREEN_WIDTH;
}

void fill(const char filler)
{

	for (uint16_t i = 0; i < SCREEN_CELLS; i++) {
		video_map[i].attribute = 0x07;
		video_map[i].print = filler;
	}
}

void clear()
{
	fill(' ');
}