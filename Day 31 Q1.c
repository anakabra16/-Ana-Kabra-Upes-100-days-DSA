#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// push operation
void push(int val) {
  if (top == MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  stack[++top] = val;
}

// pop operation
void pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    return;
  }
  printf("%d\n", stack[top--]);
}

// display stack
void display() {
  if (top == -1) {
    printf("Stack is Empty\n");
    return;
  }

  for (int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      int val;
      scanf("%d", &val);
      push(val);
    } else if (type == 2) {
      pop();
    } else if (type == 3) {
      display();
    }
  }

  return 0;
}