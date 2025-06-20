#include <stdio.h>
#include <string.h>


void itoa(int n, char s[]) {
  if (n < 0) {
    n = -n;
    s[0] = '-';
  }

  if (n > 1)
    itoa(n/10, s);
  s[strlen(s)] = n % 10 + '0';
}

int main() {
  char s[100];
  itoa(-1234, s);
  printf("%s\n", s);
}
