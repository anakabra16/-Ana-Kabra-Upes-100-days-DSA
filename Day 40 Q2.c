#include <stdlib.h>

int *dailyTemperatures(int *temperatures, int n, int *returnSize) {

  int *result = (int *)calloc(n, sizeof(int)); // initialize with 0
  int *stack = (int *)malloc(sizeof(int) * n);

  int top = -1;

  for (int i = 0; i < n; i++) {

    // resolve previous colder days
    while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
      int idx = stack[top--];
      result[idx] = i - idx;
    }

    // push current index
    stack[++top] = i;
  }

  *returnSize = n;
  return result;
}