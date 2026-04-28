#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Using prefix sum + frequency array (simple hash)
  int prefix = 0;
  int count = 0;

  // large range handling (shift index)
  int freq[20001] = {0};
  int offset = 10000;

  freq[offset] = 1; // prefix sum = 0 initially

  for (int i = 0; i < n; i++) {
    prefix += arr[i];

    // if prefix seen before → add its frequency
    count += freq[prefix + offset];

    freq[prefix + offset]++;
  }

  printf("%d\n", count);

  return 0;
}