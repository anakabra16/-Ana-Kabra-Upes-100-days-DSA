#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int val;
  int index;
} Pair;

int count[100005];

void merge(Pair arr[], int left, int mid, int right) {
  int i = left, j = mid + 1, k = 0;
  Pair temp[right - left + 1];

  while (i <= mid && j <= right) {
    if (arr[i].val <= arr[j].val) {
      count[arr[i].index] += (j - (mid + 1));
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid) {
    count[arr[i].index] += (j - (mid + 1));
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (i = left, k = 0; i <= right; i++, k++) {
    arr[i] = temp[k];
  }
}

void mergeSort(Pair arr[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  Pair arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].val);
    arr[i].index = i;
    count[i] = 0;
  }

  mergeSort(arr, 0, n - 1);

  // Output result
  for (int i = 0; i < n; i++) {
    printf("%d ", count[i]);
  }

  return 0;
}