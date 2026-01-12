#include <stdio.h>

int main(int argc, char **args) {
  /* Variante 1 */
  int i;
  printf("Anzahl der parameter ist %d\n", argc);

  for (i = 0; i < argc; i++) {
    printf("Parameter %d ist <%s>", i, args[i]);
  }

  /* Durchlaufen der Zeiger */
  /* Variante 2 */
  i = 0;
  char **a = args;
  for (; a != NULL; a++) {
    printf("Parameter ist <%s>", args[i]);
  }

	return 0;
}

