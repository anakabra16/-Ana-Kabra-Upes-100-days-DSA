#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size,
                       int *returnSize) {
  int freq[1001] = {0};

  // Step 1: count frequency
  for (int i = 0; i < arr1Size; i++) {
    freq[arr1[i]]++;
  }

  int *result = (int *)malloc(arr1Size * sizeof(int));
  int idx = 0;

  // Step 2: place elements in arr2 order
  for (int i = 0; i < arr2Size; i++) {
    int val = arr2[i];
    while (freq[val] > 0) {
      result[idx++] = val;
      freq[val]--;
    }
  }

  // Step 3: remaining elements in ascending order
  for (int i = 0; i <= 1000; i++) {
    while (freq[i] > 0) {
      result[idx++] = i;
      freq[i]--;
    }
  }

  *returnSize = arr1Size;
  return result;
}