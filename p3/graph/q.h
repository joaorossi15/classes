#define MAX 100

typedef struct {
  int data[MAX];
  int front;
  int rear;
} Queue;

void init_queue(Queue *q);

int is_empty(Queue *q);

void enqueue(Queue *q, int value);

int dequeue(Queue *q);
