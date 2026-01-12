#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *src) {
  int len = 0;
  for (len = 0; src[len] != '\0'; len++)
    ;

  return len;
}

int mystrlen2(char *src) {
  int len = 0;
  while (src[len] != '\0')
    len++;
  return 0;
}

void mystrcopy(char *dst, char *src) {

  int len = mystrlen(src);
  int c;

  for (c = 0; c < len; c++)
    dst[c] = src[c];
  dst[len] = '\0';
}

void mystrappend(char *dst, char *src) {
  int len_curr = mystrlen(src);
  int len_append = mystrlen(dst);
  int c;

  for (c = 0; c < len_append; c++)
    dst[c + len_curr] = src[c];

  dst[len_append + len_curr] = '\0';
}

int main(void) {
  char *s1 = NULL;
  s1 = (char *)malloc(sizeof(char) * 24);
  mystrcopy(s1, "Mustermann");
  mystrappend(s1, "Gommemode");
  printf("s1 ist %s", s1);
  free(s1);

  return EXIT_SUCCESS;
}
