#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *create(void) {
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  return l;
}

void insert(List *l, int v) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  tmp->value = v;
  tmp->next = l->head;
  l->head = tmp;
}

void push(List *list, int value) {
  Node *new = malloc(sizeof(Node));

  new->value = value;
  new->next = NULL;

  if (list->head == NULL) {
    list->head = new;
    return;
  }

  Node *p = list->head;

  while (p->next != NULL) {
    p = p->next;
  }

  p->next = new;
}

void print_list(List *l) {
  printf("LIST: ");
  for (Node *tmp = l->head; tmp != NULL; tmp = tmp->next)
    printf("%d, ", tmp->value);

  printf("\n");
}

int find(List *l, int v) {
  for (Node *tmp = l->head; tmp != NULL; tmp = tmp->next) {
    if (tmp->value == v) {
      return 1;
    }
  }
  return 0;
}

void rm(List *l, int v) {
  Node *last = NULL;
  Node *tmp = l->head;

  while (tmp != NULL && tmp->value != v) {
    last = tmp;
    tmp = tmp->next;
  }

  if (tmp != NULL) {
    if (last == NULL) {
      l->head = tmp->next;
    } else {
      last->next = tmp->next;
    }
    free(tmp);
  }
}

int is_empty(List *l) { return (l->head == NULL); }

void destroy(List *l) {
  Node *tmp = l->head;

  while (tmp != NULL) {
    Node *t = tmp->next;
    free(tmp);
    tmp = t;
  }

  free(l);
}
