#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int)*k);
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

bool insertFront(MyCircularDeque* obj, int value) {
    if(obj->size == obj->capacity)
        return false;

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;
    if(obj->rear == -1)
        obj->rear = obj->front;

    return true;
}

bool insertLast(MyCircularDeque* obj, int value) {
    if(obj->size == obj->capacity)
        return false;

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    return true;
}

bool deleteFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool deleteLast(MyCircularDeque* obj) {
    if(obj->size == 0)
        return false;

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int getFront(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;
    return obj->arr[obj->front];
}

int getRear(MyCircularDeque* obj) {
    if(obj->size == 0)
        return -1;
    return obj->arr[obj->rear];
}

bool isEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool isFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}