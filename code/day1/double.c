#include <stdio.h>

int main(void) {
  double d = 2.4;
  float f = 4.5;

  double de = d + f;
  double fe = d + f;
  
	printf("de is: %0.2f", de);
	printf("fe is: %0.2f", fe);

	return 0;
}
