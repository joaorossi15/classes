#include "q.h"
#define MAX 100

void init_queue(Queue *q) {
  q->front = 0;
  q->rear = 0;
}

int is_empty(Queue *q) { return q->front == q->rear; }

void enqueue(Queue *q, int value) { q->data[q->rear++] = value; }

int dequeue(Queue *q) { return q->data[q->front++]; }
