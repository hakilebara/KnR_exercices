/**
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard eaders and by direct computation. Harder if your compute them
 * :determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main() {
  printf("Signed char range: %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("Unsigned char range: %d to %d\n", 0, UCHAR_MAX);
  printf("Signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Unsigned short range: %d to %d\n", 0, USHRT_MAX);
  printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
  printf("Unsigned int range: %u to %u\n", 0, UINT_MAX);
  printf("Signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned long range: %lu to %lu\n", 0L, ULONG_MAX);

  return 0;
}
