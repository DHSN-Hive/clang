#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *src) {
  int len = 0;
  for (; *src != '\0'; src++, len++)
    ;
  return len;
}

void mystrcopy(char *dst, char *src) {

  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
}

void mystrcopy2(char *dst, char *src) {
  for (; *src != '\0'; dst++, src++)
    *dst = *src;
  *dst = '\0';
}

void mystrcat(char *dst, char *src) {
  dst = dst + mystrlen(src);
  for (; *src != '\0'; dst++, src++)
    *dst = *src;
  *dst = '\0';
}

void mystrcat2(char *dst, char *src) { mystrcopy2(dst + mystrlen(src), src); }

int main(void) {
  char *s1 = (char *)malloc(sizeof(char) * 24);

  mystrcopy(s1, "Mustermann");
  mystrcat(s1, "Mustermann");

  printf("s1 ist %s", s1);
  free(s1);
  s1 = NULL;

  return 0;
}
