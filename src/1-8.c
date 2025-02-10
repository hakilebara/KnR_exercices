/*
 * Write a program to count blanks, tabs, and newlines.
 */
#include <stdio.h>

int main() {
  long nc = 0;
  int c;
  while((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n') {
      ++nc;
    }
  printf("Blank, tabs, and newlines count: %ld\n", nc);
  return 0;
}
