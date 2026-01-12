#include <stdio.h>

int main(void) {
  long l1 = 34, l2 = 35;
  long *lp1 = &l1, *lp2 = &l2;

  printf("l1 ist %ld und liegt auf der Adresse %p", l1, lp1);
  printf("l1 ist %ld und liegt auf der Adresse %p", *lp1, &l1);

  printf("l2 ist %ld und liegt auf der Adresse %p", l2, lp2);
  printf("l2 ist %ld und liegt auf der Adresse %p", *lp2, &l2);
	return 0;
}

/*
l1 ist 34 und liegt auf der Adresse 0x16b0e2dc0
l1 ist 34 und liegt auf der Adresse 0x16b0e2dc0
l2 ist 35 und liegt auf der Adresse 0x16b0e2db8
l2 ist 35 und liegt auf der Adresse 0x16b0e2db8
*/
