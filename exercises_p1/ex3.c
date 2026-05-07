#include <stdio.h>

void swap(char **s1, char **s2) {
  char *temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}

int main() {
  char *s1 = "abc";
  char *s2 = "def";

  swap(&s1, &s2);

  printf("s1 = %s, s2 = %s\n", s1, s2);

  return 0;
}
