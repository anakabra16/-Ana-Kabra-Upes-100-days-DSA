#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// push
void push(int val) {
  if (top == MAX - 1)
    return; // overflow ignored
  stack[++top] = val;
}

// pop
void pop() {
  if (top == -1)
    return; // underflow ignored
  top--;
}

// display
void display() {
  for (int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  // push n elements
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    push(val);
  }

  int m;
  scanf("%d", &m);

  // pop m elements
  for (int i = 0; i < m; i++) {
    pop();
  }

  // print remaining stack
  display();

  return 0;
}