#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} Queue;

Queue *create();
void enqueue(Queue *q, int v);
int dequeue(Queue *q);
int is_empty(Queue *q);

#endif
