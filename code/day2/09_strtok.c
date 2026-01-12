#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *s = (char *)malloc(sizeof(char) * 1024);
  strcpy(s, "muster;Hans;Mustermann;Musterstr;4");

  char *username = strtok(s, ";");
  char *firstname = strtok(NULL, ";");
  char *lastname = strtok(NULL, ";");
  char *strasse = strtok(NULL, ";");
  char *strassennummer = strtok(NULL, ";");

  /* Wärte ausgeben */
  printf("Username %s", username);
  printf("Firstname %s", firstname);
  printf("Lastname %s", lastname);
  printf("Straße %s", strasse);
  printf("Stra0enNr %s", strassennummer);

  printf("unser String ist %s", s);
  free(s);
  s = NULL;
  return EXIT_SUCCESS;
}

/*
 * Aufgaben:
 * Was passiert beim Ausführen von strtok? // sequenz wird bis zu gegebenen character auf 0 gesetzt
 * Warum ist strtok gefährlich? // s wird als gobale variable gesetzt
 * Wie wird der String aufgeteilt?
 * Warum wird strtok heute noch verwendet? // Gibt nichts schnelleres
 * Warum muss der Speicher von Firstname, Lastname, Street und Streetnr nicht freigegeben werden?
 *
 */
