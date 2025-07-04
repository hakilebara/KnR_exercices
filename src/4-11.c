/*
 * Modify getop so that it doesn't need to use ungetch. Hint: use an internal
 * static variable.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVAL  100
#define BUFSIZE 100
#define MAXOP   100
#define NUMBER  '0'     /* signal that a number was found */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)         /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
} 

void ungetch(int c)     /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
  int i, c;
  static int lastc = 0;

  for(;;) {
    if (lastc) {
      s[0] = c = lastc;
      lastc = 0;
    } else {
      s[0] = c = getch();
    }
    if (c == ' ' || c == '\t')
      continue;
    else
      break;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;           /* not a number */
  i = 0;
  if (isdigit(c))       /* collect the integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  lastc = c;
  return NUMBER;
}

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
