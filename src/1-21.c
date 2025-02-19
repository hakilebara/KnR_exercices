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
  int c, pos, spaces;
  pos = spaces = 0;
  while ((c = getchar()) != EOF) {

    // At every tabstop, I print the spaces I have counted
    if (pos % TAB_STOP == 0) {
      if (spaces == TAB_STOP) {
        putchar('\t');
        spaces = 0; 
      }
      else {
        for (; spaces > 0; --spaces) {
          putchar(' ');
        }
      }
    } 

    if (c == ' ') {
      ++spaces;
      ++pos;
    } else if (c == '\n') { // reset counters on new line
      putchar(c);
      pos = 0;
      spaces = 0;
    } else {
      // If I encounter a non blank char, I print the spaces I have counted
      for (; spaces > 0; --spaces) {
        putchar(' ');
      }
      spaces = 0;
      putchar(c);
      ++pos;
    }
  }
}
