#include <stdio.h>
#include <stdlib.h>

struct datum {
  int tag;
  int monat;
  int jahr;
};

struct datum getDatum() {
  struct datum rc;
  rc.tag = 12;
  rc.monat = 1;
  rc.jahr = 2026;
  return rc;
}

void printDatum(struct datum d) {
  printf("Datum ist: %d:%d:%d\n", d.tag, d.monat, d.jahr);
}

int main(void) {
  /* Statisch allokieren */
  struct datum d1;
  d1 = getDatum();
  printDatum(d1);

  /* Dynamisch allokieren */
  struct datum *d2 = NULL;
  d2 = (struct datum *)malloc(sizeof(struct datum));
  d2->tag = 12;
  d2->monat = 1;
  d2->jahr = 2026;

  printDatum(*d2);
  free(d2);
  d2 = NULL;

  return 0;
}
