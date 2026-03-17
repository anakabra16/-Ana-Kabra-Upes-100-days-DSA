#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    
    char *tokens[] = {"2","1","+","3","*"};
    int n = 5;

    for(int i = 0; i < n; i++) {

        if(strcmp(tokens[i], "+") == 0) {
            int b = pop();
            int a = pop();
            push(a + b);
        }

        else if(strcmp(tokens[i], "-") == 0) {
            int b = pop();
            int a = pop();
            push(a - b);
        }

        else if(strcmp(tokens[i], "*") == 0) {
            int b = pop();
            int a = pop();
            push(a * b);
        }

        else if(strcmp(tokens[i], "/") == 0) {
            int b = pop();
            int a = pop();
            push(a / b);
        }

        else {
            push(atoi(tokens[i]));
        }
    }

    printf("Result = %d", pop());

    return 0;
}