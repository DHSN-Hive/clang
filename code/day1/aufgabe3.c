#include <stdbool.h>
#include <stdio.h>

/*
 * Wir sollen Primzahlen berechen
 * Keine werte sollen gespeichert werden. Es kann also alles von Grundauf
 * berechnet.
 */

int main(void) {

  long number_count = 5;
  long last_prime_number = 3;
  long found_prime_number = 5;
  long prime_number_count = 3;
  long operations = 0;
  bool cond = true;

  while (cond) {
    number_count++;
    for (int div = number_count - 1; div > 1; div--) {
      // Check if the number is dividable by 2, 3, 5
      if (number_count % 2 == 0 || number_count % 3 == 0 ||
          number_count % 5 == 0)
        break;

      // Check if the current iteration is a divisor of the current number
      if (number_count % div == 0) {
        break;
      }

      last_prime_number = found_prime_number;
      found_prime_number = number_count;
      prime_number_count++;

      double prime_number_percantage =
          ((double)prime_number_count / (double)number_count) * 100;
      printf("Prime Nummer %ld is the %ldth prime number that was found "
             "(Current percantage: %f)\n",
             found_prime_number, prime_number_count, prime_number_percantage);
      break;
    }
  }

  return 0;
}
