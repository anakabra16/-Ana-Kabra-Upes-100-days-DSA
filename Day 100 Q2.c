#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int val;
  int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int result[]) {
  int i = left, j = mid + 1, k = 0;
  Pair temp[right - left + 1];

  int rightCount = 0;

  while (i <= mid && j <= right) {
    if (arr[j].val < arr[i].val) {
      temp[k++] = arr[j++];
      rightCount++; // smaller element found
    } else {
      result[arr[i].index] += rightCount;
      temp[k++] = arr[i++];
    }
  }

  while (i <= mid) {
    result[arr[i].index] += rightCount;
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (i = left, k = 0; i <= right; i++, k++) {
    arr[i] = temp[k];
  }
}

void mergeSort(Pair arr[], int left, int right, int result[]) {
  if (left >= right)
    return;

  int mid = left + (right - left) / 2;

  mergeSort(arr, left, mid, result);
  mergeSort(arr, mid + 1, right, result);

  merge(arr, left, mid, right, result);
}

int *countSmaller(int *nums, int n, int *returnSize) {
  *returnSize = n;

  int *result = (int *)calloc(n, sizeof(int));
  Pair *arr = (Pair *)malloc(n * sizeof(Pair));

  for (int i = 0; i < n; i++) {
    arr[i].val = nums[i];
    arr[i].index = i;
  }

  mergeSort(arr, 0, n - 1, result);

  free(arr);
  return result;
}