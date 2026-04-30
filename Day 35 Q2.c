#include <stdbool.h>
#include <stdlib.h>


#define MAX 1000

typedef struct {
  int s1[MAX];
  int s2[MAX];
  int top1;
  int top2;
} MyQueue;

// create queue
MyQueue *myQueueCreate() {
  MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
  obj->top1 = -1;
  obj->top2 = -1;
  return obj;
}

// push
void myQueuePush(MyQueue *obj, int x) { obj->s1[++obj->top1] = x; }

// helper: move s1 → s2
void transfer(MyQueue *obj) {
  while (obj->top1 != -1) {
    obj->s2[++obj->top2] = obj->s1[obj->top1--];
  }
}

// pop
int myQueuePop(MyQueue *obj) {
  if (obj->top2 == -1)
    transfer(obj);

  return obj->s2[obj->top2--];
}

// peek
int myQueuePeek(MyQueue *obj) {
  if (obj->top2 == -1)
    transfer(obj);

  return obj->s2[obj->top2];
}

// empty
bool myQueueEmpty(MyQueue *obj) { return (obj->top1 == -1 && obj->top2 == -1); }

void myQueueFree(MyQueue *obj) { free(obj); }