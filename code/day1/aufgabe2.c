#include <stdio.h>
/*
 * Zahl soll eingegeben werden. Bei 0 soll Programm abgebrochen werden.
 * Zahl soll dann binär ausgegeben werden.
 */

void div(int number) {
  if (number <= 1) {
    printf("%d", number);
    return;
  }

  int new = number / 2;
  int mod = new % 2;
  div(new);
  printf("%d", mod);
}

int main(void) {
  int i = 0;

  while (i == 0) {
    printf("Bitte geben sie eine Zahl ein, oder drücken sie 0 um abzubrechen!");
    scanf("%d", &i);

    /* Gebe Code für die Ausgabe als Binär */
    div(i);
  }

  return 0;
}
