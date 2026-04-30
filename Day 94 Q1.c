#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
  // Step 1: Find max
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }

  // Step 2: Frequency array
  int *count = (int *)calloc(max + 1, sizeof(int));

  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  // Step 3: Prefix sum
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Step 4: Build output (stable → traverse from right)
  int output[n];

  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // Copy back
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  free(count);
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  countingSort(arr, n);

  // Print sorted array
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}