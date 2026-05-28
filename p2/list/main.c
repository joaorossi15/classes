#include "list.h"
#include <stdio.h>

int main(void) {
  List *l = create();

  insert(l, 1);
  insert(l, 2);
  insert(l, 3);
  insert(l, 4);
  insert(l, 5);
  insert(l, 6);
  insert(l, 7);
  insert(l, 8);
  push(l, 999);
  print_list(l);
  rm(l, 1);
  rm(l, 5);
  rm(l, 8);
  print_list(l);

  int found = find(l, 4);
  found == 1 ? printf("4 is on the list\n") : printf("4 is not on the list\n");

  destroy(l);

  return 0;
}
