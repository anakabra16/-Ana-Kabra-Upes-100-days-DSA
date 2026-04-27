#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[n + 1]; // extra space for new element

  // input array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int pos, x;
  scanf("%d", &pos);
  scanf("%d", &x);

  // shift elements to the right
  for (int i = n; i >= pos; i--) {
    arr[i] = arr[i - 1];
  }

  // insert element
  arr[pos - 1] = x;

  // print updated array
  for (int i = 0; i <= n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}