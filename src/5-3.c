/*
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 */
#include <stdio.h>

/* concatenate t at the end of s, s must be big enough*/
void _strcat(char *s, char *t) {
  while(*s++)
    ;
  --s;
  while((*s++ = *t++))
    ;
}

int main() {
  char s[] = "Hello";
  char t[] = " World!";

  _strcat(s, t);
  printf("%s\n", s);
  return 0;
}
