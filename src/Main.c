

#include "io.h"
#include "keyboard.h"
#include "string.h"
#include "memory.h"

void OS_Start()
{
	map_keyboard();
	clear();
	uint8_t key = 5;
	print("Keyboard testing :\n");
	print("Creating dynmamic memory\n");
	char *dynamic = memloc(1);
	dynamic[0] = '\0';

	do {
		wait_scan_code();
		key = read_scan_code();
		if (key == 42 || key == 54) {
			maj_pressed = 1;
		} else if (key == 170 || key == 182) {
			maj_pressed = 0;
		} else if (key == 14) {
			cursor--;
			print(" ");
			cursor--;
		}

		//		print("KEY=%d\n", key);
		char c = get_char(key);

		if (c != 0) {
			char *nw_pointer = memrealloc(dynamic, 1);
			if (nw_pointer != NULL) {
				int dyn_len = strlen(dynamic) + 2;
				dynamic = nw_pointer;
				dynamic[dyn_len - 2] = c;
				dynamic[dyn_len - 1] = '\0';
				print("Buffer(%d) at %s\n", dyn_len, dynamic);
			} else {
				print("Max heap reached\n");
			}

			//			print("%c", c);
		}

	} while (key != 1);
	print("The end\n");
}
