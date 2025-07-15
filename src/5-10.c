/*
 * Write the program expr, which evaluates a reverse Polish expression fro the
 * command line, where each operator and operand is a separate argument. 
 * For example,
 * expr 2 3 4 + \* (note: make sure to escape the wildcard character)
 * evaluates 2 * (3+4)
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER 1
#define STACKMAX  100

int stack[STACKMAX];
int sp = 0;

void push(int);
int pop();
int getop(char *);

int main(int argc, char *argv[]) {
  int type;

  while (--argc > 0 && (type = getop(*++argv)) ) {
    switch (type) {
      case NUMBER:
        push(atof(*argv));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
    }
  }
  printf("%d\n", pop());
}

int _isnumber(char *s) {
  while (!isdigit(*s++))
    return 0;
  return 1;
}

int getop(char *s) {
  if (_isnumber(s))
    return NUMBER;
  else
    return s[0];
}

void push(int c) {
  if (sp >= STACKMAX)
    printf("Maximum stack size exceeded\n");
  else
    stack[sp++] = c;
}

int pop() {
  if (sp > 0)
    return stack[--sp];
  else {
    printf("Stack is empty\n");
    return 0;
  }
}
