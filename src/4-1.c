/*
 * Write the function strindex(s,t) which returns the positoin of the rightmost occurrence of t in s, or -1 if there is none.
 */
#include <string.h>
#include <stdio.h>
int strindex(char s[], char t[]) {
  int i,j,k;
  for (i=strlen(s)-1; i>=0; --i) {
    for (j=i, k=strlen(t)-1; k>=0 && t[k]==s[j]; k--,j--) {
      if (k==0) {
        return i - (strlen(t) - 1);
      }
    }
  }
  return -1;
}

int main() {
  char s[] = "boujour";
  char t[] = "ou";

  printf("%d\n", strindex(s,t));
}
