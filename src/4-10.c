/*
 * An alternate organiztion uses getline to read an entire input line; this
 * makes getch and ungetch unnecessary. Revise the calculator to use this
 * approach.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXVAL   100
#define BUFSIZE  100
#define MAXOP    100
#define NUMBER   '0'    /* signal that a number was found */
#define FUNCTION '1'    /* signal that a function was found */
#define SETVAR   '2'    /* sets a variable */  
#define USEVAR   '3'    /* use a variable */
#define SPACE    '4'

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

double vars[26];

int pos = 0;

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

int _getline(char line[], int lim)
{
  int i;
  char c;

  i = 0;
  while (--lim > 0 && ( c = getchar() ) != EOF && c != '\n')
    line[i++] = c;
  
  if (c == '\n')
    line[i++] = '\n';

  line[i] = '\0';
  return i;
}

/* getop: get next character or numeric operand */
int getop(char s[], char line[])
{
  int i, c;

  while ((s[0] = c = line[pos++]) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  i = 0;

  if (c == '=') {
    s[0] = line[pos++];
    return SETVAR;
  }
  if (isupper(c))
    return USEVAR;
  if (isalpha(c)) {
    while(isalpha(s[++i] = line[pos++]))
      ;
    s[i] = '\0';
    --pos;
    return strlen(s) > 1 ? FUNCTION : c;
  }
  if (!isdigit(c) && c != '.' && c != '-') {
    return c;
  }
  if (isdigit(c))       /* collect the integer part */
    while (isdigit(s[++i] = c = line[pos++]))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = line[pos++]))
      ;
  if (c == '-') {
    // peek into the next char to know whether '-' is followed by a digit
    char t = line[pos];

    // if '-' is followed by a digit I consider it as the negative sign
    if (isdigit(t))
      while (isdigit(s[++i] = c = line[pos++]))
        ;
    else
      // otherwise '-' is the minus operator
      return c;
  }
  s[i] = '\0';
  --pos;
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
  char v;
  double ans;             /* holds the most recently printed value */
  char line[100];
  int lim = 500;

  while (_getline(line, lim) > 0) {
    while ((type = getop(s, line)) != '\n') {
      switch (type) {
      case SPACE:
        break;
      case NUMBER:
        push(atof(s));
        break;
      case FUNCTION:
        if (strcmp(s, "sin") == 0)
          push(sin(pop()));
        else if (strcmp(s, "exp") == 0)
          push(exp(pop()));
        else if (strcmp(s, "pow") == 0) {
          op2 = pop();
          push(pow(pop(), op2));
        }
        else if (strcmp(s, "ans") == 0) {
          printf("ANS: %f\n", ans);
        }
        else
          printf("error: unknown command %s\n", s);
        break;
      case SETVAR:
        v = s[0];
        if (isupper(v)) {
          vars[v - 'A'] = pop();
        }
        else {
          printf("error: variables must be upper case: %s\n", s);
        }
        break;
      case USEVAR:
        v = s[0];
        push(vars[v - 'A']);
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
      default:
        printf("error: unknown command %s\n", s);
        break;
      }
    }
    ans = pop();
    printf("\t%.8g\n", ans);
    pos = 0;
  }
  return 0;
}
