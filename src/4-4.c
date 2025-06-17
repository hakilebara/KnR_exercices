/*
 * Add the commands to print the top elements of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear the
 * stack.
 */
#include <stdio.h>
#include <ctype.h>
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

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c;           /* not a number */
  i = 0;
  if (isdigit(c))       /* collect the integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '-') {
    // peek into the next char to know whether '-' is followed by a digit
    char t = getch();
    ungetch(t);

    // if '-' is followed by a digit I consider it as the negative sign
    if (isdigit(t))
      while (isdigit(s[++i] = c = getch()))
        ;
    else
      // otherwise '-' is the minus operator
      return c;
  }
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

void dump() {
  printf("\nStack Dump: \n");
  for(int pos = sp - 1; pos >= 0; --pos) {
    printf("stack index pos:%d\t%.8g\n", pos, val[pos]);
  }
}

void clear() {
  sp = 0;
}

/* reverse Polish calculator */
int main() {
  int type;
  double op2, op3;
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
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case 'p':           /* print the top elements of the stack */   
      dump();
      break;
    case 'd'            /* duplicate the top element of the stack */:
      op2 = pop();
      push(op2);
      push(op2);
      break;
    case 's':           /* swap the top two elements of the stack */
      op2 = pop();
      op3 = pop();
      push(op2);
      push(op3);
      break;
    case 'c':           /* clear the stack */
      clear();
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
