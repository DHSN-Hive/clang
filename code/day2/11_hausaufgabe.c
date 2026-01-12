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

// Aufgabe:
// Lesen einer Datei mit Struktur
// abc:abc:abc
// dbe:127:TTT
//
// Ausgabe in eine Neue Datei => TAB Seperiert => : zu tab ersetzen
//
// Datei aufruf mit parameter srcdatei: dstdatei:
//
// Schlüsselwörter
// FILE;gets;puts;fgets;fopen;fclose
