#include "stack.h"
#include <stdio.h>

int main(void) {
  Stack *s = create();

  push(s, 10);
  push(s, 20);
  push(s, 30);

  printf("top: %d\n", peek(s));

  printf("removed: %d\n", pop(s));
  printf("removed: %d\n", pop(s));
  printf("removed: %d\n", pop(s));
  // printf("removed: %d\n", pop(s));
  // printf("removed: %d\n", pop(s));
  // printf("removed: %d\n", pop(s));

  destroy(s);

  return 0;
}
