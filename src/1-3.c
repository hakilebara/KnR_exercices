/*
 * Modify the temperature conversion program to print
 * a heading above the table
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
  int fahr = LOWER;

  printf("Fahrenheit  Celsius\n");
  while (fahr <= UPPER) {
    printf("%10d %8.1f\n", fahr, (5.0/9.0)*(fahr - 32));
    fahr+=STEP;
  }
  return 0;
}
