#include <stdio.h>

int sum_pairs(int n) {
  if (n <= 0) {
    return 0;
  }

  if (n % 2 == 0) {
    return n + sum_pairs(n - 2);
  }

  return sum_pairs(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d\n", sum_pairs(n));

  return 0;
}
