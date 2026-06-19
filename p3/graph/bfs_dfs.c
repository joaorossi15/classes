#include "q.h"
#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];

void add_edge(int src, int dest) {
  graph[src][dest] = 1;
  graph[dest][src] = 1;
}

int DFS(int v, int n, int target) {
  visited[v] = 1;

  if (v == target) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (graph[v][i] == 1 && !visited[i]) {
      parent[i] = v;
      if (DFS(i, n, target))
        return 1;
    }
  }

  return 0;
}

void BFS(int graph[MAX][MAX], int n, int start, int target) {
  int visited[MAX] = {0};
  Queue q;

  init_queue(&q);

  visited[start] = 1;
  enqueue(&q, start);

  while (!is_empty(&q)) {
    int current = dequeue(&q);

    if (current == target)
      return;

    for (int i = 0; i < n; i++) {
      if (graph[current][i] == 1 && !visited[i]) {
        visited[i] = 1;
        parent[i] = current;
        enqueue(&q, i);
      }
    }
  }
}

void reset_visited(int n) {
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }
}

void print_path(int v) {
  if (v == -1)
    return;

  print_path(parent[v]);
  printf("%d ", v);
}

int main() {
  int n = 10;

  add_edge(0, 1);
  add_edge(0, 2);

  add_edge(1, 3);
  add_edge(2, 3);

  add_edge(3, 4);
  add_edge(4, 5);
  add_edge(5, 6);
  add_edge(6, 7);

  add_edge(1, 8);
  add_edge(8, 9);
  add_edge(9, 7);

  add_edge(0, 7);

  for (int i = 0; i < n; i++)
    parent[i] = -1;

  printf("DFS path: ");
  DFS(0, n, 7);
  print_path(7);

  reset_visited(n);

  for (int i = 0; i < n; i++)
    parent[i] = -1;

  printf("\nBFS path: ");
  BFS(graph, n, 0, 7);
  print_path(7);

  return 0;
}
