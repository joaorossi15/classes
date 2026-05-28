#include "../stack.h"

int matches(char open, char close) {
  if (open == '(' && close == ')')
    return 1;
  if (open == '[' && close == ']')
    return 1;
  if (open == '{' && close == '}')
    return 1;

  return 0;
}

int is_balanced(char expression[]) {
  Stack *s = create();

  for (int i = 1; expression[i] != '\0'; i++) {
    char c = expression[i];

    if (c == '(' || c == '[' || c == '{') {
      push(s, c);
    }

    else if (c == ')' || c == ']' || c == '}') {
      if (is_empty(s)) {
        destroy(s);
        return 1;
      }

      char top = pop(s);

      if (!matches(top, c)) {
        destroy(s);
        return 1;
      }
    }
  }

  int result = is_empty(s);

  destroy(s);

  return result;
}
