#include "../stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  default:
    printf("wrong operator.\n");
    return -1;
  }
}

int main(void) {
  Stack *s = create();

  char expr[] = "5 1 2 + 4 * + 3 -";
  char *tk = strtok(expr, " ");

  while (tk != NULL) {
    if (isdigit(tk[0])) {
      push(s, atoi(tk));
    } else {
      int b = pop(s);
      int a = pop(s);

      int res = calculate(a, b, tk[0]);
      push(s, res);
    }

    tk = strtok(NULL, " ");
  }

  printf("result = %d\n", pop(s));
  return 0;
}
