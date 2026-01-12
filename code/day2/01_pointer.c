#include <stdio.h>

// & für Referenz
// * für Dereferenz
int main(void) {

  int i = 3;
  printf("%d", i);

  /* Zeigervariablen */
  /* Pointer ist immer 64 bit */
  int *ip1 = NULL;
  int *ip2 = NULL;

  ip1 = &i;
  ip2 = &i;

  printf("ip2 auf 777 setzen");
  *ip2 = 777;

  printf("i = %d, ip1 = %d, ip2 = %d", i, *ip1, *ip2);

  /* Pointer mit ausgeben */
  printf("i = %p, ip1 = %p, ip2 = %p", &i, ip1, ip2);
  return 0;
}
