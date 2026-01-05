#include <stdio.h>

// Hier werden sogannte bits benutzt um Eigenschaften darzustellen (Bit-Flags)
// & wird verwendet um zu abzufragen ob eine Eigenschaft exestiert
// | wird verwendet um eine Eigenschaft zu setzten

const is_dir = 0x1;
const can_exe = 0x2;
const can_write = 0x4;
const can_read = 0x8;

int main(void) { 

	int sec = 0;
	/* Setzen der Eigenschaften */

	sec = sec | can_write;
	sec = sec | can_read;

	printf("Sec is %d", sec);


	if(is_dir == (sec & is_dir)) {
		printf("Sec ist directory");
	} else {
		printf("Sec ist kein directory");
	}

	return 0; 
}
