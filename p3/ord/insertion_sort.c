#include <stdio.h>

void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while ((j >= 0) && (arr[j] > key)) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
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

  insertion_sort(arr, n);

  printf("after sorting: ");
  print_arr(arr, n);

  return 0;
}
