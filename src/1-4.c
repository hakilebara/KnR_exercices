/*
 * Write a program to print the corresponding Celius to
 * Fahrenheit table.
 * 
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
  int celc = LOWER;

  printf("Celsius Fahrenheit\n");
  while (celc <= UPPER) {
    printf("%7d %10.1f\n", celc, (9.0/5.0)*celc + 32);
    celc+=STEP;
  }
  return 0;
}
