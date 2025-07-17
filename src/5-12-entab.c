/*
 * Extend entab and detab to accept the shorthand entab -m +n to mean tab stops
 * every n columns, starting at column m. Choose convenient (for the user)
 * default behaviour.
 */
#include <stdio.h>
#include <stdlib.h>

#define TAB_STOP 2

int main(int argc, char *argv[]) {
  int c, colstart, tabstop, has_args;
  int nb, pos, is_tab_stop;
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

  for (pos = 1; (c = getchar()) != EOF; ++pos) {
    if (c == ' ') {
      // use default tab settings if there are no arguments
      is_tab_stop = has_args 
        ? pos > colstart && (pos - colstart) % tabstop == 0
        : pos % TAB_STOP == 0;
      if (is_tab_stop) {
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
