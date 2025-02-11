/*
 * Revise the main routine of the longest line program so it will correctly
 * print the length of arbitrary long input lines, and as much as possible of
 * the text.
 */
#include <stdio.h>

#define MAX_LENGTH 20

int _getline(char s[], int lim);
void copy(char to[], char from[]);

int main() {
  int len;                  // length of current line
  int max; 
  char longest[MAX_LENGTH]; // longest line buffer
  char line[MAX_LENGTH];    // current line buffer

  len = max = 0;
  
  while((len = _getline(line, MAX_LENGTH)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  printf("Longest line size: %d\n", max);
  printf("Longest line: %s\n", longest);

  return 0;
}

int _getline(char s[], int lim) {
  int c, i, d;
  d = 0;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 2) {    // need to store space for '\n' and '\0'
      s[d] = c;
      ++d;
    }
  }
  if (c == '\n') {
    s[d] = c;
    ++i;
    ++d;
  }
  s[d] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
