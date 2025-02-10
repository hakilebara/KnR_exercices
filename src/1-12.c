/* Write a program that prints its input one word per line */
#include <stdio.h>

#define  IN   1
#define  OUT  0

int main() {
  
  int c, state;
  c = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        state = OUT;
        putchar('\n');
      }
    }
    else {
      state = IN;
      putchar(c);
    }

  }
  putchar('\n');
}
