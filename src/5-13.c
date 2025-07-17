/*
 * Write the program tail, which prints the last n lines of its input. By
 * default, n is set to 10, let us say, but it can be changed by an optional
 * argument so that 
 *  tail -n
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALLOCMAX 50000
#define MAXLINES 500
#define MAXLEN   100

#define TAIL 10

char buf[ALLOCMAX];
char *bufp = buf;

char *alloc(size_t n);
int _getline(char* line, int lim);
int readlines(char *lineptr[], int maxlines);

int main(int argc, char *argv[]) {
  char *lineptr[MAXLINES];
  int nlines, tail;
  nlines = 0;
  tail = TAIL;

  if (argc > 1)
  {
    if (argv[1][0] == '-')
      tail = atoi(++argv[1]);
    else {
      printf("tail: illegal option -- %s\n", argv[1]);
      return -1;
    }
  }
      
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    int i;
    for (i = nlines - tail; i < nlines; ++i)
      printf("%s\n", lineptr[i]);
  }
  return nlines;
}

int readlines(char *lineptr[], int maxlines) {
  char *p, line[MAXLEN];
  int i, len;

  i = 0;
  while ((len = _getline(line, MAXLEN)) > 0) {
    if (i >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; //removes the trailing \n
      strcpy(p, line);
      lineptr[i++] = p;
    }
  }
  return i;
}

int _getline(char *line, int lim) {
  int i, c;
  i = 0;
  while (i < lim-1 && (c = getchar()) != EOF && c != '\n')
    line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

char *alloc(size_t n) {
  if (bufp + n < buf + ALLOCMAX) {
    bufp += n;
    return bufp - n;
  }
  else
    return NULL;
}
