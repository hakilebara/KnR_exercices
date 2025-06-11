/*
 * Extend atof to handle scientific notation of the form 123.45e-6 where a
 * floating-point number may be followed by e or E and an optionally signed
 * exponent
 */
#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]) {
  double val;
  int power, i, sign, e, esign;

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
  esign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    ++i;
  for (e = 0; isdigit(s[i]); ++i) {
    e = (s[i] - '0') + e * 10;
  }
  return (sign * val / power) * pow(10, esign * e);
}
int main() {
  printf("%.8f\n", atof("123.45e-6"));
  return 0;
}
