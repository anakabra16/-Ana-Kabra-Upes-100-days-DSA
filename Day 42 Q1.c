#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {

    int n, x;

    scanf("%d", &n);

    // read queue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // move queue to stack
    while(front <= rear) {
        push(dequeue());
    }

    // move stack back to queue
    front = 0;
    rear = -1;

    while(top >= 0) {
        enqueue(pop());
    }

    // print reversed queue
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}