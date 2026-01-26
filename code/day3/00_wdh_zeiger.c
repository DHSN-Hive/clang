#include <stdio.h>  /*printf, scanf*/
#include <stdlib.h> /*malloc, free*/
#include <string.h> /*strcpy, memcpy*/

int main(void) {
  /* Arbeiten mit Puffer */
  char *puffer = (char *)malloc(sizeof(char) * 1024);
  printf("Geben Sie einen Namen ein: ");
  scanf("%s", puffer);

  /* Schreiben in Zielspeicher */
  /* Speicher reservieren + 1 Byte für '\0'  */
  char *sname = (char *)malloc(sizeof(char) * (strlen(puffer) + 1));
  strcpy(sname, puffer);

  /* Puffer freigeben */
  free(puffer);

  /* Daten verarbeiten und ausgeben */
  printf(
      "Der String ist [%s], hat eine Länge von %ld und steht an Adresse %p\n",
      sname, strlen(sname), sname);

  /* sname in Speicher freigeben */
  free(sname);
  sname = NULL;
  return 0;
}
