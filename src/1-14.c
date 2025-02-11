/*
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 */
#include <stdio.h>

int main() {
  int c;
  int charfreq[128] = {0}; // does not handle extended ASCII codes

  while((c = getchar()) != EOF) {
    ++charfreq[c];
  }

  for(int i = 0; i < 128; ++i) {
    if (charfreq[i] > 0) {
      if (i >= 32 && i <= 127) // if the character is printable
        printf("'%c': ", i); // then print the character
      else
        printf("x%02X: ", i); // otherwise display its hex code
      for (int j = 0; j < charfreq[i]; ++j)
        printf("#");
      printf("\n");
    }
  }
}
