#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

// enqueue
void enqueue(int val) {
  if (rear == MAX - 1) {
    printf("Queue Overflow\n");
    return;
  }
  queue[++rear] = val;
}

// display
void display() {
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  // insert elements
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    enqueue(val);
  }

  // display queue
  display();

  return 0;
}