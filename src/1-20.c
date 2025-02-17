/*
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every n columns. Should n be a variable or a symbolic parameter?
 * Expected output
 * Hello\t\tWorld  -> Hello   World 
 * Hell\t\tWorld   -> Hell    World
 */

#include <stdio.h>

#define TAB_STOP 2
                
int main() {
  int c, cursor_position;
  cursor_position = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int space_shift = TAB_STOP - ( cursor_position % TAB_STOP );
      for (int j = 0; j < space_shift; ++j) {
        putchar(' ');
        ++cursor_position;
      }
    }
    else if (c == '\n') {
      putchar(c);
      cursor_position = 0; // resets the cursor position
    }
    else {
      putchar(c);
      ++cursor_position;
    }
  }
}
