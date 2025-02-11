/*
 * Modify the temperature conversion program to print
 * a heading above the table
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_celc(float fahr) {
  return (5.0/9.0)*(fahr - 32);
}

int main()
{
  int fahr = LOWER;

  printf("Fahrenheit  Celsius\n");
  while (fahr <= UPPER) {
    printf("%10d %8.1f\n", fahr, fahr_to_celc(fahr));
    fahr+=STEP;
  }
  return 0;
}
