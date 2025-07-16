/*
 * Modify the program entab and detab (written as exercices in Chapter 1) to
 * accept a list of tab stops as arguments. Use the default tab settings if
 * there are no arguments.
 */
#include <stdio.h>
#include <stdlib.h>

#define TAB_STOP 4

int get_tab_stop(int pos, char* tabstops[]);

int main(int argc, char *argv[]) {
  int c, pos, nb;
  pos = 1;
  nb = 0;

  while((c = getchar()) != EOF) {
    if (c == '\t') {
      nb = (argc > 1) 
        ? get_tab_stop(pos, argv+1) - (pos-1)
        : TAB_STOP - (pos-1) % TAB_STOP;
      while (nb-- > 0) {
        putchar('s');
        ++pos;
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

int get_tab_stop(int pos, char *tabstops[]) {
  while(*tabstops) {
    if (atoi(*tabstops) > pos)
      return atoi(*tabstops);
    ++tabstops;
  }
  return 0;
}
