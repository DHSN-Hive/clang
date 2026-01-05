#include <stdio.h>
/*
 * Rekursion
 */

// Speicher wird zusätzlich für alle lokalen variablen und parameter frei gemacht
// obwohl a und b schon in main allocated sind, werden sie hier als param wieder allocated
// c wird als neue variablendeklaration schon allocated
int plus(int a, int b) { // allocation of 8 bytes
  int c = a + b; // allocation of 4 bytes => 32 bit
  return c;
}

int main(void) {
  int i1 = 2, i2 = 5;
  int i3 = plus(i1, i2);

  printf("Ergebniss %d + %d = %d", i1, i2, i3);
  return 0;
}
