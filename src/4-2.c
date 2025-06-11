#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {
  double val;
  int power, i, sign, e;

  val = 0;

  // remove blanks
  for (i = 0; isspace(s[i]); ++i)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (; isdigit(s[i]); ++i) {
    val = 10 * val + (s[i] - '0');
  }
  if (s[i] == '.')
    ++i;
  for (power = 1; isdigit(s[i]); ++i) {
    val = 10 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E')
    ++i;
  for (e = 0; isdigit(s[i]); ++i) {
    e = (s[i] - '0') + e * 10;
  }
  return (sign * val / power) * pow(10, e);
}
int main() {
  printf("%.2f\n", atof("123.45e6"));
  return 0;
}
