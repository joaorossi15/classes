#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
  int items[MAX];
  int top_index;
} Stack;

Stack *create(void);
void push(Stack *s, int v);
int pop(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
int peek(Stack *s);
void destroy(Stack *s);

#endif
