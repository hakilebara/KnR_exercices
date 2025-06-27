/*
 * Rewrite appropriate programs from earlier chapters and exercices with pointers instead of array indexing. Good possibilities include getline, atoi, itoa, and their variants, reverse, and strindex and getop
 */
#include <stdio.h>
#include <ctype.h>

#define BUFMAX 10
#define NUMBER 0

int buf[BUFMAX];
int bufp = 0;

int getch(void) {
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp < BUFMAX)
    buf[bufp++] = c;
  else
    printf("ungetch: maximum buffer size exceeded\n");
}

/* getline: get line into s, return length */
int _getline(char *s, int lim) {
  int c;
  char* ss = s;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - ss;
}

/* atoi: convert s to integer */
int atoi(char* s) {
  int i, sign;
  i = 0;
  sign = 1;
  while (*s) {
    if (*s == '-')
      sign = -1;
    if (isdigit(*s))
      i = i * 10 + (*s - '0');
    ++s;
  }
  return i * sign;
}

/* reverse: reverse string s in place */
void reverse(char* s) {
  char temp; 
  char *ss = s;
  while (*s)
    ++s;
  while (ss < s) {
    temp = *ss;
    *ss++ = *--s;
    *s = temp;
  }
}

/* itoa: convert n in characters in s */
void itoa(int n, char* s) {
  char* ss = s;
  do {
    *s++ = n % 10 + '0';
  }
  while ((n /= 10) > 0);
  *s = '\0';
  reverse(ss);
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
  char *start, *ss, *tt;
  for (start = s; *s; ++s) {
    for (ss = s, tt = t; *tt && *ss == *tt; ++ss, ++tt)
      ;
    if (tt > t && !*tt)
      return s - start;
  }
  return -1;
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') 
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

/* getop: get next character or numeric operand */
int pgetop(char *s) {
  int c;
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s+1) = '\0';
  if (!isdigit(c) && c != '.') 
    return c;
  if (isdigit(c))
    while (isdigit(*++s = c = getch()))
      ;
  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;
  *s = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

int main() {
  printf("atoi: %d\n", atoi(" -12345"));

  char s1[10];
  itoa(12345, s1); 
  printf("itoa: %s\n", s1);

  printf("strindex: %d\n", strindex("hello", ""));
}
