#include <stdio.h>

// zu beginn dieser Funktion werden alle variablen kopiert, es wir also eine
// neue erstellt so bleibt ergebnis nur eine kopie von z und wird am ende der
// funktion deconstructed somit bleibt z unverändert obwohl ergebnis auf 11
// gesetzt wird
void plus1(int ergebnis, int a, int b) {
  /* Diese Funktion funktioniert nicht */

  ergebnis = a + b;
  printf("Plus1: a=%d, b=%d ergebnis=%d", a, b, ergebnis);
}

// hier werden auch x und y kopiert und a und b werden neu konstruiert
// für z wird aber eine kopie des Pointers erstellt und hinein gegeben
// *z zeigt aber auf die selbe adresse wie *ergebnis
// so kann in der Funktion z verändert werden
void plus2(int *ergebnis, int a, int b) {
  /* Diese Funktion funktioniert nicht */

  *ergebnis = a + b;
  printf("Plus1: a=%d, b=%d ergebnis=%d", a, b, *ergebnis);
}
int main(void) {
  int x = 5, y = 6, z = 0;
  plus1(z, x, y);
  printf("z ist nun %d", z);

  plus2(&z, x, y);
  printf("z ist nun %d", z);
  return 0;
}
