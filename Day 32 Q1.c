#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

void pop() {
    if(top >= 0)
        top--;
}

int main() {

    int n, m, x;

    scanf("%d",&n);

    // push elements
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }

    scanf("%d",&m);

    // pop elements
    for(int i=0;i<m;i++){
        pop();
    }

    // display remaining stack
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }

    return 0;
}