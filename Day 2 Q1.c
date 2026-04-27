#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];

  // input array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int pos;
  scanf("%d", &pos);

  // shift elements to the left
  for (int i = pos - 1; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }

  // print updated array (size n-1)
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}