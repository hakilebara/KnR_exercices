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
  while(m-- > 0)    /* Pad with '\0's if s has fewer characters than n */
    *s++ = '\0';
  *(s-1) = '\0';    /* Make sure the return string always ends with \0 */
  return ss;
}

char * _strncat(char *s, char *t, size_t n) {
  char *ss = s;
  while (*s)
    ++s;
  while (n-- > 0 && (*s++ = *t++))
    ;
  *(s-1) = '\0';
  return ss;
}
int _strncmp(char *s, char *t, int n) {
  for (; --n > 0 && *s == *t; ++s, ++t)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

int main() {
  char s[50];
  char t[] = "abc-def-ghi";
  printf("%s\n", _strncpy(s, t, sizeof(s))); 

  char s2[50] = "Hello";
  printf("%s\n", _strncat(s2, " World!", 7));

  printf("%d\n", _strncmp("abcd", "abce", 3));
}
