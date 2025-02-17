/**
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time
 */
#include <stdio.h>

#define MAX_LENGTH 1000

int _getline(char s[], int lim);
void reverse(char s[]);
int trim(char s[]);

int main() {
  char s[MAX_LENGTH];

  while (_getline(s, MAX_LENGTH) > 0) {
    reverse(s);
    printf("%s\n", s);
  }

  return 0;
}

int _getline(char s[], int lim) {
  int c, i, j;
  i = j = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < lim - 2) {
      s[i] = c;
      ++j;
    }
    ++i;
  }
  if (c == '\n') {
    s[j] = c;
    ++j;
    ++i;
  }
  s[j] = '\0';

  return i;
}

void reverse(char s[]) {
  int len = trim(s);
  int i, j;

  i = 0;
  j = len - 2;

  while ((i <= len - 2) && (j > i)) {
      char temp;
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
      ++i;
      --j;
  }
}

int trim(char s[]) {
  int i;
  for (i = 0; s[i] != '\n' && s[i] != '\0'; ++i)
    ;

  if (s[i] == '\0' || s[i] == '\n')
    --i;

  while (s[i] == ' ' || s[i] == '\t')
    --i;

  if (i > 0) {
    s[++i] = '\n';
    s[++i] = '\0';
  }

  return i;
}
