#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char = 1 Byte
// char* = 8 Byte
// char** = 8 Byte
int main(void) {
  // hier wird ein pointer auf Stack allokiert
  char **a = NULL; // 8 Byte
  // Hier werden 5 weitere Pointer auf Heap allokiert
  a = (char **)malloc(sizeof(char *) * 5); // 40 Byte

  // hier werden weitere 64 Byte allokiert
  a[0] = (char *)malloc(sizeof(char) * 16); // 16 Byte
  a[1] = (char *)malloc(sizeof(char) * 16); // 32 Byte
  a[2] = (char *)malloc(sizeof(char) * 16); // 48 Byte
  a[3] = (char *)malloc(sizeof(char) * 16); // 64 Byte
  a[4] = NULL;                              // 64+0

  strcpy(a[0], "maxMuster");
  strcpy(a[1], "mr.pinguin");
  strcpy(a[2], "batman");
  strcpy(a[3], "BlueBalls");

  int i;
  for (i = 0; a[i] != NULL; i++) {
    printf("String %s ist %p", a[i], a[i]);
  }

  // Erst auf 2. Ebene befreien
  for (i = 0; a[i] != NULL; i++) {
    free(a[i]);
  }
  free(a);
}
