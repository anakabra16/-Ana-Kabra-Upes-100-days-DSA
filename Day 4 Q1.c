#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];

  // input array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int start = 0, end = n - 1;

  // two-pointer reversal
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }

  // print reversed array
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}