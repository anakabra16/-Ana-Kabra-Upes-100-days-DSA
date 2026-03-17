#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int main(){

    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(int i=0;i<strlen(infix);i++){

        char ch = infix[i];

        if(isalnum(ch)){
            printf("%c",ch);
        }

        else if(ch=='('){
            push(ch);
        }

        else if(ch==')'){
            while(stack[top] != '(')
                printf("%c",pop());
            pop();
        }

        else{
            while(top!=-1 && precedence(stack[top]) >= precedence(ch))
                printf("%c",pop());

            push(ch);
        }
    }

    while(top!=-1)
        printf("%c",pop());

    return 0;
}