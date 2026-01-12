#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *ip1 = NULL;
  long *lp1 = NULL;

  /* Dynamischer Speicher */
  ip1 = (int *)malloc(sizeof(int));
  lp1 = (long *)malloc(sizeof(long));

  *ip1 = 23;
  *lp1 = 24;

  // Ausgabe
  printf("ip1 ist %d mit der Adresse %p", *ip1, ip1);
  printf("lp1 ist %ld mit der Adresse %p", *lp1, lp1);

  free(ip1);
  free(lp1);

	// Use after Free kann vermediet werden wenn variable selbst gleich null gesetzt wird
	// ip1 = NULL;
	// Also Pointervariablen auf NULL setzen

  // Fehler bei Ausgabe `Use After Free`
  printf("ip1 ist %d mit der Adresse %p", *ip1, ip1);
  printf("lp1 ist %ld mit der Adresse %p", *lp1, lp1);

  return 0;
}
