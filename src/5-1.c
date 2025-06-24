/*
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push a character back on the input.
 */
#include <stdio.h>
#include <ctype.h>

#define BUFMAX 100

int buf[BUFMAX];
int bufp = 0;

int getch() {
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp < BUFMAX)
    buf[bufp++] = c;
  else
    printf("Maximum buffer size exceeded\n");
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;
  
  while(isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    while(!isdigit(c = getch()))
      ;
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn = *pn * sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main() {
  int a; 
  int* p = &a;

  getint(p);

  printf("%d\n", *p);
}
