#include <stdio.h>
#include <string.h>

void swap(char *s1, char *s2) {
  char temp[100];

  strcpy(temp, s1);
  strcpy(s1, s2);
  strcpy(s2, temp);
}

int main() {
  char s1[100], s2[100];

  scanf("%s %s", s1, s2);

  swap(s1, s2);

  printf("S1 = %s, S2 = %s\n", s1, s2);

  return 0;
}
