/*
 * Write the function strend(s,t), which returns 1 if the string t occurs at
 * the end of the string s, and zero otherwise.
 */
#include <stdio.h>

int strend(char *s, char *t) {
  while(*s != *t)
    ++s;
  for(; *s == *t; ++s, ++t)
    if (*s == '\0')
      return 1;
  return 0;
}

int main() {
  char s[] = "hello";
  char t1[] = "lo";
  char t2[] = "llo";

  printf("%d\n", strend(s, t1));    /* Should return 0 */
  printf("%d\n", strend(s, t2));    /* Should return 1 */
  return 0;
}
