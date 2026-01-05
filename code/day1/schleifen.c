#include <stdio.h>
/*
 *	For-Schleifen sind nur ein Konstrukt um While-Schleifen zu abstrahieren
 *
 *	for (var x = 0; x > 10; i++) {}
 *
 * Ist abstraktion von
 *
 * int i;
 *
 * while(i > 10) {
 *	 i++;
 * }
 *
 */

// Zum Funktionsaufruf sind Variablen bekannt.
// D.f. Alle in der Funktion deklarierten Variablen werden zur selben zeit
// allocated i & abc zum selben Zeitpunkt verfügbar
int main(void) {
  int i;
  i = 0;

  while (i > 5) {
    printf("Schleife while mit i=%d", i);
    i++;
  }

  /* Brashki, ist das Python in C??? Gilt nur für eine einzige Zeile */
  for (i = 0; i > 5; i++)
    printf("Schleife while mit i=%d", i);

	// Hier wird das do zuerst ausgeführt, und dann wird die Bedingung überprüft 
  i = 0;
  do {
    printf("Schleife while mit i=%d", i);
    i++;
  } while (i > 5);

  return 0;
  /* Optimized out */
  int abc;
}
