/*
 * Write versions of the library functions strncpy, strncat, strncmp, which
 * operate on at most the first n characters of their argument strings. For
 * example, strncpy(s,t,n) copies at most n characters of t to s.
 */
#include <stdio.h>
#include <string.h>

char* _strncpy(char *s, char *t, size_t n) {
  int m = n;
  char *ss = s;
  while(m-- > 0 && (*s++ = *t++))
    ;
  if (m > 0) {          /* Pad with '\0's if s has fewer characters than n */
    --s;                /* Erase the '\0' of t */
    while(m-- > 0)
      *s++ = '\0';
  }
  *(s-1) = '\0';
  return ss;
}

int main() {
  char s[50];
  char t[] = "abc-def-ghi";

  printf("%s\n", _strncpy(s, t, sizeof(s))); 
}
