#include <stdio.h>
#include <stdlib.h>

// Skalare Var
// var[stelle] => dereferenz
// var[0] == *var
int main(void) {
  char *vorname = NULL;

  /* Speicher reservieren */
  vorname = (char *)malloc(sizeof(char) * 16); // Sizeof char = 1

  /* Speicher beschreiben */
  vorname[0] = 'A';
  vorname[1] = 'R';
  vorname[2] = 'A';
  vorname[3] = 'R';
  vorname[4] = 'A';
  vorname[5] = 'T';
  vorname[6] = '\0';

  printf("vorname %s", vorname);

  int i;
  for (i = 0; i < 16; i++)
    printf("Zeichen %c an Stellte %d hat Speicherstelle %p \n\r", vorname[i], i,
           &vorname[i]);

	free(vorname);
	vorname = NULL;

  return EXIT_SUCCESS;
}
