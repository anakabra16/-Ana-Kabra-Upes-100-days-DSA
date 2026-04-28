#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// create list
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

// delete first occurrence of key
struct Node *deleteKey(struct Node *head, int key) {

  // case 1: head is the key
  if (head != NULL && head->data == key) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  struct Node *curr = head;
  struct Node *prev = NULL;

  while (curr != NULL && curr->data != key) {
    prev = curr;
    curr = curr->next;
  }

  // key found
  if (curr != NULL) {
    prev->next = curr->next;
    free(curr);
  }

  return head;
}

// print list
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node *head = createList(n);

  int key;
  scanf("%d", &key);

  head = deleteKey(head, key);

  printList(head);

  return 0;
}