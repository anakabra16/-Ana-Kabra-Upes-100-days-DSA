#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {

    if((rear + 1) % MAX == front)
        return;

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;
}

int dequeue() {

    int value = queue[front];

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return value;
}

void display() {

    int i = front;

    while(1) {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {

    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int temp = dequeue();
        enqueue(temp);
    }

    display();

    return 0;
}