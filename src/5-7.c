/*
 * Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?
 */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char linestorage[]);
void writelines(char *lineptr[], int nlines);

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define ALLOCSIZE 1000           /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

/* return pointer to n characters */
char *alloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
    allocp += n;
    return allocp -n;       /* old p */
  } else                    /* not enough room */
    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)        /* do nothing if array contains */
    return;                 /* fewer than two elements */
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

#define MAX_LINE_STORAGE 10000
/* sort input lines */
int main()
{
  int nlines;               /* number of input lines read */
  char linestorage[MAX_LINE_STORAGE];

  if ((nlines = readlines(lineptr, MAXLINES, linestorage)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000         /* max length of any input line */
int _getline(char *s, int lim) {
  int c;
  char* ss = s;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - ss;
}

char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char linestorage[])
{
  int len, nlines;
  char *p, line[MAXLEN], *linestoragestop;
  p = linestorage;
  linestoragestop = linestorage + MAX_LINE_STORAGE;

  nlines = 0;
  while ((len = _getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || p + len >= linestoragestop)
      return -1;
    else {
      line[len-1] = '\0';   /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
      p+=len;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
