#include <stdio.h>

int fib(int n) {
  // base cases
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  // recursive call
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d\n", fib(n));

  return 0;
}