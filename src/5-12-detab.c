/*
 * Modify the program entab and detab (written as exercices in Chapter 1) to
 * accept a list of tab stops as arguments. Use the default tab settings if
 * there are no arguments.
 */
#include <stdio.h>
#include <stdlib.h>

#define TAB_STOP 4

int main(int argc, char *argv[]) {
  int c, pos, nb;
  int colstart, tabstop, has_args;
  pos = 1;
  nb = 0;

  if ((has_args = argc > 1))
    while (--argc > 0 && (c = (*++argv)[0]) ) {
      switch (c) {
        case '-':
          colstart = atoi(++argv[0]);
          break;
        case '+':
          tabstop = atoi(++argv[0]);
          break;
        default:
          printf("entab: illegal option %c\n", c);
          colstart = -1;
          tabstop = -1;
          break;
      }
    }

  while((c = getchar()) != EOF) {
    if (c == '\t') {
      if (has_args && pos < colstart) 
        putchar('\t');
      else {
        nb = (has_args) 
          ? tabstop - (pos - colstart) % tabstop 
          : TAB_STOP - (pos-1) % TAB_STOP;
        while (nb-- > 0) {
          putchar('s');
          ++pos;
        }
      }
    } else {
      if (c == '\n')
        pos = 1;
      else
        ++pos;
      putchar(c);
    }
  }
}
