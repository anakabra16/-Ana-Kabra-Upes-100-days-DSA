#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push(int x) {
    stack1[++top1] = x;
}

void transfer() {
    while(top1 >= 0) {
        stack2[++top2] = stack1[top1--];
    }
}

int pop() {
    if(top2 == -1) {
        transfer();
    }
    return stack2[top2--];
}

int peek() {
    if(top2 == -1) {
        transfer();
    }
    return stack2[top2];
}

bool empty() {
    return (top1 == -1 && top2 == -1);
}

int main() {

    push(1);
    push(2);

    printf("Peek: %d\n", peek());
    printf("Pop: %d\n", pop());

    if(empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}