#ifndef LIST_H
#define LIST_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} List;

List *create(void);
void destroy(List *l);
void insert(List *l, int v);
void push(List *l, int v);
void rm(List *l, int v);
int is_empty(List *l);
int find(List *l, int v);
void print_list(List *l);

#endif
