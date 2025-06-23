/*
 * Define a macro swap(t, x, y) that interchanges two arguments of type t.
 * (Block structure will help.)
 */

/* #define swap(t,x,y) void swap(t x, t y) {  }  */
#include <stdio.h>

#define swap(t, x, y) { t _temp;      \
                        _temp = x;  \
                        x = y;        \
                        y = _temp; }  \

int main() {
  int x = 10;
  int y = 12;
  swap(int, x, y);

  printf("x: %d, y: %d\n", x, y);
}
