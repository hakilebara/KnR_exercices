/**
 * Write a function setbits(x, p, n, y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged
 */
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  y = y & ~(~0<<n);
  unsigned bitmask = ~(~(~0 << n) << (p+1-n));
  x = x & bitmask; 
  return x | y << (p+1-n);
}

int main(void) {
  printf("%d\n", setbits(26, 7, 3, 7));
}
