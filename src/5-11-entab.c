/*
 * Modify the program entab and detab (written as exercices in Chapter 1) to
 * accept a list of tab stops as arguments. Use the default tab settings if
 * there are no arguments.
 */
#include <stdio.h>
#include <stdlib.h>

#define TAB_STOP 2

int get_tab_stop(char *tabstops[], int pos);

int main(int argc, char *argv[]) {
  int c, nb, pos, is_tab_stop;
  nb = 0; // counter of blank spaces
  for (pos = 1; (c = getchar()) != EOF; ++pos) {
    if (c == ' ') {
      // use default tab settings if there are no arguments
      is_tab_stop = (argc > 1) ? get_tab_stop(argv+1, pos) : pos % TAB_STOP == 0;
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

// returns 1 if a given position is found in a list of tabstops, 0 otherwise
int get_tab_stop(char *tabstops[], int pos) {
  while (*tabstops) {
    if (atoi(*tabstops) == pos)
      return 1;
    ++tabstops;
  }
  return 0;
}
