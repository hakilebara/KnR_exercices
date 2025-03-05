/**
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a swtich. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */
#include <stdio.h>

void escape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; ++i) {
    switch (s[i]) {
      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
        break;
      case '\t':
        t[j++] = '\\';
        t[j++] = 't';
        break;
      default:
        t[j++] = s[i];
        break;
    }
  }
}

void unescape(char s[], char t[]) {
  int i, j, in_seq;
  in_seq = 0;
  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] == '\\')
      in_seq = 1;
    else if (in_seq) {
      switch(s[i]) {
        case 'n':
          t[j++] = '\n';
          break;
        case 't':
          t[j++] = '\t';
          break;
        default: // leave the escape sequence unchanged
          t[j++] = '\\';
          t[j++] = s[i];
          break;
      }
      in_seq = 0;
    }
    else
      t[j++] = s[i];
  }
}

int main(void) {
  char s[] = "Bon\tjour";
  char t[10];
  escape(s, t);
  printf("%s\n", t);
  char u[10];
  unescape("Bon\\tjour", u);
  printf("%s\n", u);
}
