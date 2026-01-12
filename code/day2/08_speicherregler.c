#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // Allocated 3x8 Byte für Pointer (im Stack)
  char *s1 = NULL, *s2 = NULL, *s3 = NULL;

  /* Speicher reservieren */
  // Allocated 3x12 Byte im Heap:w
  s1 = (char *)malloc(sizeof(char) * 12);
  s2 = (char *)malloc(sizeof(char) * 12);
  s3 = (char *)malloc(sizeof(char) * 12);

  /* Speicher beschreiben */
  strcpy(s1, "Wert 1");
  strcpy(s2, "Wert 2");
  strcpy(s3, "Wert 3");

  // Sollte die aktuelles statment mehr memory brauchen als gegeben so gibt es
  // einen fehler denn s2 würde hier den puffer überschreiebn und bis s3 kommen
  // und dies auch überschreiben compiler gibt nur ein warning aus!
  strcpy(s2, "Yap yap yappidie yap yap yapp yappa yap yap");

  /* Ausgabe */
  printf("s1 ist %s und zeigt auf Adresse %p", s1, s1);
  printf("s2 ist %s und zeigt auf Adresse %p", s2, s2);
  printf("s3 ist %s und zeigt auf Adresse %p", s3, s3);

  /* Speicher Freigeben */
  free(s1);
  free(s2);
  // da s2 überschreibt und schon befreit wurde wird hier einen fehler geworfen,
  // da der speicher bereits frei ist
  free(s3);

  /* Speicher sichern */
  s1 = NULL;
  s2 = NULL;
  s3 = NULL;

  return EXIT_SUCCESS;
}

// Um dieses Problem zu lösen:
// s2 = realloc(s2, sizeof(char)*x);
// wobei x die benötigte Größe ist
// Damit wird neuer speicher zugewiesen und alle fehler sind behoben!
