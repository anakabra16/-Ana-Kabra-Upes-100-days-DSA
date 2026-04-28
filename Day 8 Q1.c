#include <stdio.h>

int power(int a, int b) {
  // base case
  if (b == 0)
    return 1;

  // recursive case
  return a * power(a, b - 1);
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  printf("%d\n", power(a, b));

  return 0;
}