#include <stdio.h>
#include <stdlib.h>

int strsize(char * str) {
  int i = 0;
  while (str[i]) i++;
  return i;
}

int main(int argc, char ** argv) {
  if (2 > argc) {
    printf("Usage : ./hex2ascii <ascii string>");
    return 0;
  }

  int s = strsize(argv[1]);

  if (1 > s) {
    printf("String given is empty !");
    return -1;
  }

  int i = -1, j = 1, c1, c2;
  char * str = malloc(1);

  for (; s > ++i;) {
    c1 = argv[1][i];
    c2 = argv[1][++i];

    c1 -= 48;
    c2 -= 48 + 7 * (64 < c2);

    c1 *= 16;

    str = realloc(str, ++j);
    str[j - 1] = c1 + c2;
  }

  str[j] = 0;

  for (i = -1; (s / 2 + 1) > ++i;) printf("%c", str[i]);
  printf("\n");

  return 0;
}
