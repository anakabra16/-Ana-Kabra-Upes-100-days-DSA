#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

// enqueue
void enqueue(int x) { queue[++rear] = x; }

// dequeue
int dequeue() { return queue[front++]; }

// push stack
void push(int x) { stack[++top] = x; }

// pop stack
int pop() { return stack[top--]; }

int main() {
  int n;
  scanf("%d", &n);

  // input queue
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    enqueue(x);
  }

  // step 1: move queue → stack
  while (front <= rear) {
    push(dequeue());
  }

  // reset queue
  front = 0;
  rear = -1;

  // step 2: move stack → queue
  while (top != -1) {
    enqueue(pop());
  }

  // print reversed queue
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }

  return 0;
}