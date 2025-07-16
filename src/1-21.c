/*
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which should be give preference?
 *
 * This is a naive implementation of entab that only handles blanks spaces ' '
 */
#include <stdio.h>

#define TAB_STOP  4

int main() {
  int c, nb, pos;
  nb = 0; // counter of blank spaces
  for (pos = 1; (c = getchar()) != EOF; ++pos) {
    if (c == ' ') {
      // use default tab settings if there are no arguments
      if (pos % TAB_STOP == 0) {
        putchar('\t');
        nb = 0;
      }
      else
        ++nb;
    }
    else {
      for (; nb > 0; --nb)
        putchar(' ');
      if ( c == '\n' )
        pos = 0;
      putchar(c);
      nb = 0;
    }
  }
}
