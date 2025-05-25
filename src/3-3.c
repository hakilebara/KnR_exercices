/**
 * Write a function expand(s1, s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits, and be prepared t handle case like a-b-c
 * and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.
 */
#include <ctype.h>
#include <stdio.h>

void expand(char s1[], char s2[]) {
  int i, j;
  char c, start, end;
  i = j = 0;
  while ((c = s1[i++]) != '\0') {
    if (s1[i] == '-' && (end = s1[i+1]) > c) {
      start = c;
      while (start <= end)
        s2[j++] = start++;
      i+=2;
    }
    else
      s2[j++] = c;
  }
  s2[j] = '\0';
}

int main(void) {
  char* inputs[] = { "a-z", "a-z0-9", "a-zCOUCOU0-9" };
  for (int i = 0; i < sizeof(inputs)/sizeof(char*); ++i) {
    char s2[100];
    expand(inputs[i], s2);
    printf("expand %-15s : %s\n", inputs[i], s2);
  }
}
