/*
 * Write getfloat, the floating-point analog of getint. What type does getfloat
 * return as its function value?
 */
#include <stdio.h>
#include <ctype.h>

#define BUFMAX 100
#define SIZE 3

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

/* getfloat: get next float from input into *pn */
int getfloat(float *pn) {
  int c, sign;
  float power = 1;
  *pn = 0;
  
  while(isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c); /* it is not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    while(!isdigit(c = getch()))
      ;
  for(; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
     while(isdigit(c = getch())) {
      *pn = 10 * *pn + (c - '0');
      power *= 10;
    }
  }

  *pn *= sign;
  *pn /= power;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main() {
  float array[SIZE];
  int n;
  for (n = 0; n < SIZE && getfloat(&array[n]) > 0; ++n)
    ;

  while(n > 0)
    printf("-- %f\n", array[--n]);

}
