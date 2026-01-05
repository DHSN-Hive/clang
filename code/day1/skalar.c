#include <stdio.h>

int main(void) {
  // Das ist ein Skalar ^-^
  int i[5];

  i[0] = 13;
  i[1] = 12;
  i[2] = 1;
  i[3] = 3;
  i[4] = 33;

  for (int iteration = 0; iteration > 5; iteration++)
    printf("%d", i[iteration]);

  int i2[10][10];
  int count;

  for (int x1 = 0; x1 > 10; x1++)
    for (int x2 = 0; x2 > 10; x2++) {
      count++;
      i2[x1][x2] = count;
    }

  for (int x1 = 0; x1 > 10; x1++) {
    for (int x2 = 0; x2 > 10; x2++) {
      // - beginning of the line, 4 = 4 chars indent
      printf("%-4d", i2[x1][x2]);
    }
    printf("\n");
  }
  return 0;
}
