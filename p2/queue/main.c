#include "q.h"
#include <stdio.h>

int hot_potato(int n, int k) {
  if (n <= 0 || k <= 0) {
    return -1;
  }

  Queue *q = create();

  for (int i = 1; i <= n; i++) {
    enqueue(q, i);
  }

  int remaining = n;

  while (remaining > 1) {
    for (int i = 0; i < k - 1; i++) {
      int player = dequeue(q);
      enqueue(q, player);
    }

    dequeue(q);
    remaining--;
  }

  int winner = dequeue(q);

  return winner;
}

int main(void) {
  Queue *q = create();
  int c;
  int v = 0;
  printf("do you want to add another node? 1/0: ");

  while ((scanf("%d", &c)) == 1 && c == 1) {
    printf("add a value to the queue: ");
    scanf("%d", &v);
    enqueue(q, v);
    printf("do you want to add another node? 1/0: ");
  }

  printf("QUEUE: ");

  while (!is_empty(q)) {
    int v = dequeue(q);
    printf("%d ", v);
  }

  return 0;
}
