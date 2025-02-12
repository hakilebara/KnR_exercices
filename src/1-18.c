/*
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines
 */
#include <stdio.h>

#define MAX_LENGTH 1000

int _getline(char s[], int lim);
int trim(char line[]);

int main () {
  int len, t_len;
  char line[MAX_LENGTH];
  while((len = _getline(line, MAX_LENGTH)) > 0) {
    if ((t_len = trim(line)) > 0)
      printf("origin length: %d, trimmed length: %d, line: %s", len, t_len, line);
  }
  return 0;
}

int trim(char line[]) {
  int i;

  for (i = 0; line[i] != '\n'; ++i);
  for (--i; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i);
  if (i > 0) {
    line[++i] = '\n';
    line[++i] = '\0';
  }
  
  return i;
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
  }
  s[j] = '\0';

  return i;
}
