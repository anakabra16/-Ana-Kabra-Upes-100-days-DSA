#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main() {
    char expr[100];
    char *token;

    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    token = strtok(expr, " \n");

    while(token != NULL) {

        if(isdigit(token[0]) || 
           (token[0]=='-' && isdigit(token[1]))) {
            push(atoi(token));
        }
        else {
            int b = pop();
            int a = pop();

            if(strcmp(token, "+") == 0)
                push(a + b);
            else if(strcmp(token, "-") == 0)
                push(a - b);
            else if(strcmp(token, "*") == 0)
                push(a * b);
            else if(strcmp(token, "/") == 0)
                push(a / b);
        }

        token = strtok(NULL, " \n");
    }

    printf("Result = %d\n", pop());

    return 0;
}