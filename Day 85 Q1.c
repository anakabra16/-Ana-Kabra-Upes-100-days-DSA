#include <stdio.h>

// Merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;

  int temp[right - left + 1];

  // Merge elements
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  // Remaining elements
  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  // Copy back to original array
  for (i = left, k = 0; i <= right; i++, k++) {
    arr[i] = temp[k];
  }
}

// Recursive merge sort
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);      // left half
    mergeSort(arr, mid + 1, right); // right half

    merge(arr, left, mid, right); // merge
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, n - 1);

  // Output
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}