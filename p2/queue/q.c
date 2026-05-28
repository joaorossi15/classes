#include "q.h"
#include <stdlib.h>

Queue *create() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  if (q == NULL) {
    return NULL;
  }

  q->head = NULL;
  q->tail = NULL;

  return q;
}

void enqueue(Queue *q, int v) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->value = v;
  n->next = NULL;

  if (q->tail != NULL) {
    q->tail->next = n;
  } else {
    q->head = n;
  }

  q->tail = n;
}

int dequeue(Queue *q) {
  if (q->head == NULL) {
    return -1;
  }

  Node *n = q->head;
  int v = n->value;
  q->head = n->next;

  if (q->head == NULL)
    q->tail = NULL;

  free(n);
  return v;
}

int is_empty(Queue *q) { return (q->head == NULL); }
