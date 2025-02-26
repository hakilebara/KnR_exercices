/**
 * Write an alternative version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in s2.
 */
#include <stdio.h>

void squeeze(char s1[], char s2[]) {
  int match, i, j, k;
  for (i = j =  0; s1[i] != '\0'; ++i) {
    match = 0;
    for (k = 0; s2[k] != '\0'; ++k) {
      if (s2[k] == s1[i]) { // match found
        match = 1;
      }
    }
    if (!match) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

int main(void) {
  char s[] = "Strawberry";
  char t[] = "ra";
  printf("Original: %21s\n", s);
  printf("Characters squeezed: ");
  for (int i = 0; t[i] != '\0'; ++i) {
    printf("%c ", t[i]);
  }
  printf("\n");
  squeeze(s, t);
  printf("Squeezed: %17s\n", s);
}
