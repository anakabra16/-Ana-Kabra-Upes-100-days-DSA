#include <stdio.h>

// Simple sorting (Insertion Sort)
void sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int x) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == x) {
      return mid; // found
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1; // not found
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort first
  sort(arr, n);

  // Print sorted array
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  // Example search (you can modify input if needed)
  int x;
  scanf("%d", &x);

  int result = binarySearch(arr, n, x);

  if (result != -1)
    printf("Found at index %d", result);
  else
    printf("Not found");

  return 0;
}