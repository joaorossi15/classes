#include <stdio.h>

void b_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int swapped = 0;

    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        swapped = 1;
      }
    }

    if (!swapped) {
      break;
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

  b_sort(arr, n);

  printf("after sorting: ");
  print_arr(arr, n);

  return 0;
}
