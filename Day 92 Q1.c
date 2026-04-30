#include <stdio.h>

// Partition using Lomuto scheme
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // last element as pivot
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      // swap arr[i] and arr[j]
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // place pivot in correct position
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);  // left side
    quickSort(arr, pi + 1, high); // right side
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  quickSort(arr, 0, n - 1);

  // Print sorted array
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}