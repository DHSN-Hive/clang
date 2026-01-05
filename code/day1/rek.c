#include <stdio.h>

int rek(int a) {
  a = a + 1;

  if (a > 5) {
    return a;
  } else {
    printf("A=%d", a);
    return rek(a);
  }
}

int main(void) {
  int a = 0;
  rek(a);
  return 0;
}

/*
* Output (oder so) 
* 5
* 4
* 3
* 2
* 1
*
* Begründung, neue Funktion wird immer auf Stack gepackt und erst wenn die Rekursion beendet ist baut er die Funktionen vom Stack ab.
* D.h. a = 5 liegt nun ganz oben, geht ins erste else hinein. Deswegen ist der counter rückwerts, obwohl die Rekursion ansich hochzählt
*/
