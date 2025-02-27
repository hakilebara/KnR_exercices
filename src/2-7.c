/**
 * Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed to 0 and vice versa), leaving the
 * others unchanged.
 */
#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n)) << (p+1-n);
}

int main(void) {
  printf("%d\n", invert(10, 3, 3));
}
