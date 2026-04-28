#include <stdio.h>

// function to reverse array
void reverse(int arr[], int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];

  // input array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int k;
  scanf("%d", &k);

  k = k % n; // handle large k

  // Step 1: reverse whole array
  reverse(arr, 0, n - 1);

  // Step 2: reverse first k elements
  reverse(arr, 0, k - 1);

  // Step 3: reverse remaining elements
  reverse(arr, k, n - 1);

  // print result
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}