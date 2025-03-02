/**
 * In a two complement number system, x &= (x-1) deletes the rightmost 1-bit in
 * x. Explain why. Use this observation to write a faster version of bitcount.
 */

#include <stdio.h>

/* bitcount: count '1' bits in  */
int bitcount(unsigned x) {
  size_t b = 0;
  while (x > 0) {
    x &= (x-1);
    b++;
  }
  return b;
}

int main(void) {
  printf("%d\n", bitcount(7)); // expects 3
  printf("%d\n", bitcount(255)); // expects 8
}
