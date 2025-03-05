/**
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a swtich. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */
#include <stdio.h>

void escape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; ++i) {
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }
  s[j] = '\0';
}

void unescape(char s[], char t[]) {
  int i, j, in_seq;
  in_seq = 0;
  for (i = j = 0; t[i] != '\0'; ++i) {
    if (t[i] == '\\')
      in_seq = 1;
    else if (in_seq) {
      switch(t[i]) {
        case 'n':
          s[j++] = '\n';
          break;
        case 't':
          s[j++] = '\t';
          break;
        default: // leave the escape sequence unchanged
          s[j++] = '\\';
          s[j++] = t[i];
          break;
      }
      in_seq = 0;
    }
    else
      s[j++] = t[i];
  }
  s[j] = '\0';
}

int main(void) {
  char t[] = "Bon\tjour";
  char s[10];
  escape(s, t);
  printf("%s\n", s);

  char u[10];
  unescape(u, "Bon\\tjour");
  printf("%s\n", u);
}
