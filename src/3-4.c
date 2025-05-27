#include <stdio.h>

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

/* itoa: convert n to chracters in s */
/* void itoa(int n, char s[]) { */
void itoa(long long n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n positive */
  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main() {
 char s[10];
 itoa(-2147483648, s);
 printf("%s\n", s);
}
