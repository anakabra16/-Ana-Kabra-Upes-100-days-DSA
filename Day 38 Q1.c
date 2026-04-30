#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *front = NULL, *rear = NULL;
int sz = 0;

// push front
void push_front(int val) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->prev = NULL;
  newNode->next = front;

  if (front != NULL)
    front->prev = newNode;
  else
    rear = newNode;

  front = newNode;
  sz++;
}

// push back
void push_back(int val) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = rear;

  if (rear != NULL)
    rear->next = newNode;
  else
    front = newNode;

  rear = newNode;
  sz++;
}

// pop front
void pop_front() {
  if (front == NULL) {
    printf("Deque is empty\n");
    return;
  }

  struct Node *temp = front;
  front = front->next;

  if (front != NULL)
    front->prev = NULL;
  else
    rear = NULL;

  free(temp);
  sz--;
}

// pop back
void pop_back() {
  if (rear == NULL) {
    printf("Deque is empty\n");
    return;
  }

  struct Node *temp = rear;
  rear = rear->prev;

  if (rear != NULL)
    rear->next = NULL;
  else
    front = NULL;

  free(temp);
  sz--;
}

// front element
void getFront() {
  if (front == NULL)
    printf("-1\n");
  else
    printf("%d\n", front->data);
}

// back element
void getBack() {
  if (rear == NULL)
    printf("-1\n");
  else
    printf("%d\n", rear->data);
}

// empty
void isEmpty() { printf("%s\n", (sz == 0) ? "true" : "false"); }

// size
void size() { printf("%d\n", sz); }

// display
void display() {
  struct Node *temp = front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// clear
void clear() {
  while (front != NULL)
    pop_front();
}

// reverse
void reverse() {
  struct Node *curr = front;
  struct Node *temp = NULL;

  while (curr != NULL) {
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }

  if (temp != NULL)
    front = temp->prev;

  // swap front & rear
  temp = front;
  front = rear;
  rear = temp;
}

// main (sample usage)
int main() {
  push_back(10);
  push_back(20);
  push_front(5);
  display(); // 5 10 20

  pop_front();
  display(); // 10 20

  getFront(); // 10
  getBack();  // 20

  size();    // 2
  isEmpty(); // false

  reverse();
  display(); // 20 10

  clear();
  isEmpty(); // true

  return 0;
}