

#include "io.h"
#include "keyboard.h"
#include "string.h"

void OS_Start()
{
	map_keyboard();
	clear();
	uint8_t key = 5;
	printf("Keyboard testing :\n");
	printf("Middle string\n");
	printf("String : %s\n", "coucou");
	do {
		wait_scan_code();
		key = read_scan_code();
		if (key == 42 || key == 54) {
			maj_pressed = 1;
		} else if (key == 170 || key == 182) {
			maj_pressed = 0;
		}else if(key == 14){
			cursor--;
			printf(" ");
			cursor--;
		}

		char c = get_char(key);
		if (c != 0) {
			printf("%c", c);
		} 

	} while (key != 1);
	printf("The end\n");
}
