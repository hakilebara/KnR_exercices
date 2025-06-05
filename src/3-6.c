/*
 * Write a version of itoa that accepts three arguents instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough.
 */
#include <stdio.h>

void reverse(char s[]) {
  int i, j;
  i = 0;
  char temp;
  for (j = 0; s[j] != '\0'; ++j);
  while (i < j) {
    temp = s[i];
    s[i++] = s[--j];
    s[j] = temp;
  }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int min_width) {
  int i, sign;
  i = 0;
  if ((sign = n) < 0) {       /* record sign */
    n = -n;                   /* make n positive */
  }
  do {
    s[i++] = n % 10 + '0';
  }
  while ((n/=10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  while (i < min_width) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

int main() {
  char s[100];
  itoa(-123, s, 8);
  printf("%s\n", s);
}
