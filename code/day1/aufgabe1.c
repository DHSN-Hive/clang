#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/* Wir sollen ohne limits zum int max kommen :Wir sollen ohne limits zum int max kommen :(( */
int main(void) {
  int max_int = INT_MAX;
  printf("%d", max_int);

  int test = 0;
  bool cond = true;
  while (cond) {
    test++;
    printf("%d", test);
  }

  // i = 2 um die bits hoch zu zählen (2 ist basis)
  int i = 2;
  while (cond)
    i = i * 2;

  // Niedrigste Zahl liegt genau eins entfernt von der größten Zahl
  i--;

  return 0;
}
