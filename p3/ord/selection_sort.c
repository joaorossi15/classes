#include <stdio.h>

void selection_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    if (min_index != i) {
      int tmp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = tmp;
    }
  }
}

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {
  int arr[] = {5, 2, 9, 1, 3};
  int n = 5;

  printf("before sorting: ");
  print_arr(arr, n);

  selection_sort(arr, n);

  printf("after sorting: ");
  print_arr(arr, n);

  return 0;
}
