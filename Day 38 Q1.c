#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if(front == -1) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if(front == 0) {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

void push_back(int x) {
    if(rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void pop_front() {
    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }
    if(front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void pop_back() {
    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }
    if(front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

int get_front() {
    if(empty()) return -1;
    return deque[front];
}

int get_back() {
    if(empty()) return -1;
    return deque[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    int i = front, j = rear;
    while(i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    for(int i = front; i <= rear; i++) {
        for(int j = i + 1; j <= rear; j++) {
            if(deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void display() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    reverse();
    display();

    sort();
    display();

    clear();
    display();

    return 0;
}