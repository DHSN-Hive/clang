#include <stdio.h>

int main(void) {
  // Das ist ein Skalar ^-^
  char i[5];

  i[0] = 'H';
  i[1] = 'a';
  i[2] = 'i';
	// begriff der 0-Terminierung kommt hiervon (ASCII)
	// y wid nach dem 0 nicht mehr ausgegebn! Ende des Literals
	// Im Kontext eines strings verfällt dies, ist aber noch ein valider character des skalars
  i[3] = '\0';
  i[4] = 'y';

  printf("%s", i);

  return 0;
}
