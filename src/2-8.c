/**
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n positions.
 */
#include <stdio.h>

unsigned rightrot(unsigned char x, int n) {
  n %= sizeof(x) * 8; // handles n >= sizeof(x);
  unsigned bitmask = x & ~(~0 << n); // saves the n bits about to be shifted out
  x >>= n;
  size_t shift = (sizeof(x) * 8) - n;
  return x | (bitmask << shift);
}

int main(void) {
  printf("%d\n", rightrot(59,3));  // expects 103
  printf("%d\n", rightrot(59,19)); // expects 103
}
