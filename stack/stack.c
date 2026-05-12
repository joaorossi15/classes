#include "stack.h"
#include <stdlib.h>

Stack *create(void) {
  Stack *s = malloc(sizeof(Stack));
  if (s == NULL) {
    return NULL;
  }

  s->top_index = -1;

  return s;
}

int is_empty(Stack *s) { return s->top_index == -1; }

int is_full(Stack *s) { return s->top_index == MAX - 1; }

void push(Stack *s, int v) {
  if (is_full(s))
    return;

  s->top_index++;
  s->items[s->top_index] = v;
}

int pop(Stack *s) {
  if (is_full(s))
    return -1;

  int v = s->items[s->top_index];
  s->top_index--;
  return v;
}

int peek(Stack *s) {
  if (is_full(s))
    return -1;

  return s->items[s->top_index];
}

void destroy(Stack *s) { free(s); }
