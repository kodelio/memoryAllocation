
#include "keyboard.h"

int maj_pressed = 0;

int altgr_pressed = 0;

void map_keyboard()
{
	//alphabet
	K_MAP('a', 'A', 30);
	K_MAP('b', 'B', 48);
	K_MAP('c', 'C', 46);
	K_MAP('d', 'D', 32);
	K_MAP('e', 'E', 18);
	K_MAP('f', 'F', 33);
	K_MAP('g', 'G', 34);
	K_MAP('h', 'H', 35);
	K_MAP('i', 'I', 23);
	K_MAP('j', 'J', 36);
	K_MAP('k', 'K', 37);
	K_MAP('l', 'L', 38);
	K_MAP('m', 'M', 50);
	K_MAP('n', 'N', 49);
	K_MAP('o', 'O', 24);
	K_MAP('p', 'P', 25);
	K_MAP('q', 'Q', 16);
	K_MAP('r', 'R', 19);
	K_MAP('s', 'S', 31);
	K_MAP('t', 'T', 20);
	K_MAP('u', 'U', 22);
	K_MAP('v', 'V', 47);
	K_MAP('w', 'W', 17);
	K_MAP('x', 'X', 45);
	K_MAP('y', 'Y', 21);
	K_MAP('z', 'Z', 44);

	//Others
	K_MAP(' ', ' ', 57);
	K_MAP('&', '1', 8);
	K_MAP('\'', '4', 40);
	K_MAP('(', '5', 10);
	K_MAP('-', '6', 12);
	K_MAP(')', '°', 11);
	K_MAP('=', '+', 13);
	
	K_MAP(',', ',', 51);
	K_MAP('>', '>', 52);
	K_MAP('?', '?', 53);
	K_MAP(';', '.', 39);
	K_MAP('!', '!', 2);



	K_MAP('1', '1', 79);
	K_MAP('2', '2', 80);
	K_MAP('3', '3', 81);
	K_MAP('4', '4', 75);
	K_MAP('5', '5', 76);
	K_MAP('6', '6', 77);
	K_MAP('7', '7', 71);
	K_MAP('8', '8', 72);
	K_MAP('9', '9', 73);
	K_MAP('0', '0', 82);

	//Special
	K_MAP('\n', '\n',28);

}

char get_char(int keycode)
{
	key_t k = keyboard_map[keycode];
	if(maj_pressed)return k.maj;
	return k.normal;
}

void set_char(char normal, char maj, uint16_t index)
{
	key_t nw_k = {.normal = normal, .maj = maj};
	keyboard_map[index] = nw_k;
}