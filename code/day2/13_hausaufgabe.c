// Aufgabe:
// Lesen einer Datei mit Inhalt
// abc:abc:abc
// dbe:127:TTT
//
// Ausgabe in eine neue Datei
// TAB seperiert => : zu \t ersetzen
//
// Datei aufruf mit parameter srcdatei: dstdatei:
// Schlüsselwörter
// FILE;gets;puts;fgets;fopen;fclose

#include <stdio.h>

int main(int argc, char *argv[]) {
  char buff[13];
  FILE *src;
  FILE *dst;

  if (argc != 3) {
    printf("Fehlende Parameter! Aufruf: %s srcdatei dstdatei\n", argv[0]);
    return 1;
  }

  // Öffen der srcdatei mit 'r' => Berechtigung zum lesen
  src = fopen(argv[1], "r");
  // Öffen der dstdatei mit 'w' => Berechtigung zum schreiben
  dst = fopen(argv[2], "w");

  if (src == NULL || dst == NULL) {
    printf("Dateifehler\n");
    return 1;
  }

  // fgets nimmt drei Parameter an
  // 1. char zum beschreiben
  // 2. Anzahl wieviel chars gelesen werden dürfen
  // 3. Datei
  while (fgets(buff, sizeof(buff), src) != NULL) {
    printf("Die aktuell eingelesene Zeile enthält: [%s]\n", buff);
    // Aktuellen eingelesenen Buffer durchgehen und ':' zu '\t' umwandeln
    for (int i = 0; buff[i] != '\0'; i++) {
      if (buff[i] == ':') {
        buff[i] = '\t';
      }
    }

    fputs(buff, dst);
  }

  fclose(src);
  fclose(dst);

  printf("Die Datei wurde erfolgreich beschrieben.");
  return 0;
}
