/**
 * Write a function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 throught 9, a through f, and A through F.
 */
#include <stdio.h>
#include <ctype.h>

int hextodigit(const char c) {
  if (isdigit(c)) {
    return c - '0';
  } 
  
  else if (c >= 'a' && c <= 'f') {
    return 10 + c - 'a';
  } 
  
  else if (c >= 'A' && c <= 'F') {
    return 10 + c - 'A';
  }

  return -1;
}

int htoi(const char s[]) {
  int i, acc, n;
  i = acc = 0;
  if (s[i] == '0') {
    ++i;
    if (s[i] == 'x' || s[i] == 'X')
      ++i;
  }
  while ((n = hextodigit(s[i])) != -1) {
    acc = 16 * acc + n;
    ++i;
  }
  return acc;
}

int main() {
  char s[] = "0xaa";
  printf("%d\n", htoi(s));
  return 0;
}
