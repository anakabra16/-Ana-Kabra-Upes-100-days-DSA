#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int *q = (int *)malloc(sizeof(int) * n);

  int front = 0, rear = -1;

  // read input values
  int *arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // enqueue all n elements
  for (int i = 0; i < n; i++) {
    rear = (rear + 1) % n;
    q[rear] = arr[i];
  }

  int m;
  scanf("%d", &m);

  // dequeue m elements
  for (int i = 0; i < m; i++) {
    front = (front + 1) % n;
  }

  // enqueue first m elements again (wrap-around effect)
  for (int i = 0; i < m; i++) {
    rear = (rear + 1) % n;
    q[rear] = arr[i];
  }

  // display circular queue
  int i = front;
  while (1) {
    printf("%d ", q[i]);
    if (i == rear)
      break;
    i = (i + 1) % n;
  }

  free(q);
  free(arr);
  return 0;
}