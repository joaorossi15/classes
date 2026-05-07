#include <stdio.h>

int count(int n) {
  if (n < 10) {
    return 1;
  }

  return 1 + count(n / 10);
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d\n", count(n));

  return 0;
}
