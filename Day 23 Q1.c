#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// function to create list
struct Node *createList(int n) {
  struct Node *head = NULL, *temp = NULL, *newNode;

  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }

  return head;
}

// function to merge two sorted lists
struct Node *merge(struct Node *l1, struct Node *l2) {
  struct Node dummy;
  struct Node *tail = &dummy;
  dummy.next = NULL;

  while (l1 != NULL && l2 != NULL) {
    if (l1->data < l2->data) {
      tail->next = l1;
      l1 = l1->next;
    } else {
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }

  // attach remaining nodes
  if (l1 != NULL)
    tail->next = l1;
  else
    tail->next = l2;

  return dummy.next;
}

// print list
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main() {
  int n, m;

  scanf("%d", &n);
  struct Node *list1 = createList(n);

  scanf("%d", &m);
  struct Node *list2 = createList(m);

  struct Node *result = merge(list1, list2);

  printList(result);

  return 0;
}