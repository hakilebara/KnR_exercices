/*
 * Write a program to print all input lines that are longer than 80 characters
 */
#include <stdio.h>

#define MAX_LENGTH 100

int _getline(char s[], int lim);

int main () {
  int len;
  char line[MAX_LENGTH];
  while((len = _getline(line, MAX_LENGTH)) > 0) {
    if (len > 80) {
      printf("%s", line);
    }  
  }
  return 0;
}

int _getline(char s[], int lim) {
  int i, c, j;
  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < lim - 2) {
      s[i] = c;
      ++j;
    }
  if (c == '\n') {
    s[j] = c;
    ++j;
    ++i;
  }
  s[j] = '\0';

  return i;
}
