/* 
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats s as a hexadecimal integer in s.
 */
#include <stdio.h>

void reverse(char s[]) {
  int i, j;
  char temp;
  i = 0;
  for (j = 0; s[j] != '\0'; ++j);
  while (i < j) {
    temp = s[i];
    s[i++] = s[--j];
    s[j] = temp;
  }
}

void itob(int n, char s[], int b) {
  int i = 0;
  do {
    if (b == 16 && n % b > 9) {
      switch (n % b) {
        case 10:
          s[i++] = 'A';
          break;
        case 11:
          s[i++] = 'B';
          break;
        case 12:
          s[i++] = 'C';
          break;
        case 13:
          s[i++] = 'D';
          break;
        case 14:
          s[i++] = 'E';
          break;
        case 15:
          s[i++] = 'F';
          break;
      }
    }
    else
      s[i++] = (n % b) + '0';
  }
  while (( n /= b) > 0);
  s[i] = '\0';
}

int main() {
  char s[100];
  itob(123, s, 2);
  reverse(s);
  printf("%s\n", s);

  itob(123, s, 3);
  reverse(s);
  printf("%s\n", s);

  itob(254, s, 16);
  reverse(s);
  printf("%s\n", s);
}
