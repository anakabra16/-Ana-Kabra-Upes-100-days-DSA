#include <stdbool.h>
#include <stdlib.h>


typedef struct {
  int *arr;
  int front;
  int rear;
  int size;
  int capacity;
} MyCircularDeque;

// create deque
MyCircularDeque *myCircularDequeCreate(int k) {
  MyCircularDeque *obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
  obj->arr = (int *)malloc(sizeof(int) * k);
  obj->front = 0;
  obj->rear = -1;
  obj->size = 0;
  obj->capacity = k;
  return obj;
}

// insert front
bool myCircularDequeInsertFront(MyCircularDeque *obj, int value) {
  if (obj->size == obj->capacity)
    return false;

  obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
  obj->arr[obj->front] = value;
  obj->size++;
  if (obj->size == 1)
    obj->rear = obj->front;

  return true;
}

// insert rear
bool myCircularDequeInsertLast(MyCircularDeque *obj, int value) {
  if (obj->size == obj->capacity)
    return false;

  obj->rear = (obj->rear + 1) % obj->capacity;
  obj->arr[obj->rear] = value;
  obj->size++;
  return true;
}

// delete front
bool myCircularDequeDeleteFront(MyCircularDeque *obj) {
  if (obj->size == 0)
    return false;

  obj->front = (obj->front + 1) % obj->capacity;
  obj->size--;
  return true;
}

// delete rear
bool myCircularDequeDeleteLast(MyCircularDeque *obj) {
  if (obj->size == 0)
    return false;

  obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
  obj->size--;
  return true;
}

// get front
int myCircularDequeGetFront(MyCircularDeque *obj) {
  if (obj->size == 0)
    return -1;
  return obj->arr[obj->front];
}

// get rear
int myCircularDequeGetRear(MyCircularDeque *obj) {
  if (obj->size == 0)
    return -1;
  return obj->arr[obj->rear];
}

// empty
bool myCircularDequeIsEmpty(MyCircularDeque *obj) { return obj->size == 0; }

// full
bool myCircularDequeIsFull(MyCircularDeque *obj) {
  return obj->size == obj->capacity;
}

// free
void myCircularDequeFree(MyCircularDeque *obj) {
  free(obj->arr);
  free(obj);
}