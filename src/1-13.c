/* 
 * Write a program to print a histogram of the lengths.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging
 */

/* 
 * Personal note: My understanding of the exercise is that
 * for the horizontal histogram, the expected output is
 * Length 01 : ####
 * Length 02 : #
 * Length 03 : #####
 * etc.
 */

#include <stdio.h>

#define IN  1
#define OUT 0

#define MAX_WORD_LENGTH 15

int main() {
  int c, state, wl;
  int wcounts [MAX_WORD_LENGTH];
  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    wcounts[i] = 0;
  }

  state = OUT;
  wl = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) { // just exited a word
        ++wcounts[wl];
      }
      state = OUT;
      wl = 0;
    }
    else if (state == OUT) { // justed entered a word
      state = IN;
      ++wl;
    }
    else {
      ++wl;
    }
  }

  
  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (wcounts[i] > 0) {
      printf("Length %2d: ", i);
      for (int j = 0; j < wcounts[i]; ++j) {
        printf("#");
      }
     printf("\n");
    }
  }

  return 0;
} 
