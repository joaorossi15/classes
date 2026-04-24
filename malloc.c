#include <stdio.h>
#include <stdlib.h>

void demo_memory_leak() {
  int *p = malloc(100 * sizeof(int));
  p[0] = 123;
  printf("[leak] allocated and forgot to free\n");
}

void demo_use_after_free() {
  int *p = malloc(sizeof(int));
  *p = 77;

  free(p);

  printf("[use-after-free] %d\n", *p);
}

int *demo_stack_return() {
  int x = 99;
  return &x;
}

int *demo_heap_return() {
  int *p = malloc(sizeof(int));
  *p = 42;
  return p;
}

char *g() {
  char *c = malloc(10 * sizeof(char));
  return c;
}

char *f() {
  char arr[] = "abc";
  return arr;
}

int *heap_large() {
  int *arr = malloc(1000000 * sizeof(int));
  arr[0] = 42;
  return arr;
}

void stack_overflow_demo() {
  int big[10000000];
  big[0] = 1;
  printf("\nStack large array first element: %d\n", big[0]);
}

void size_demo() {
  int arr[10];
  int *ptr = arr;

  printf("\n=== SIZE DEMO ===\n");
  printf("sizeof(arr) = %zu\n", sizeof(arr));
  printf("sizeof(ptr) = %zu\n", sizeof(ptr));
}

int main() {
  int *h = demo_heap_return();
  printf("[heap return] %d\n\n", *h);
  free(h);

  int *s = demo_stack_return();
  printf("[stack return] %d (undefined)\n\n", *s);

  demo_memory_leak();
  printf("\n");

  demo_use_after_free();
  printf("\n");

  char *a = g();
  printf("stack_array -> %d %d %d (undefined behavior)\n", a[0], a[1], a[2]);

  char *b = f();
  printf("stack_pointer -> %d (undefined behavior)\n", *b);

  char *c = literal();
  printf("heap_array -> %d %d %d\n", c[0], c[1], c[2]);
  free(c);

  int *d = heap_large();
  printf("heap_large -> %d\n", d[0]);
  free(d);

  stack_overflow_demo();

  return 0;
}
