#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// create circular linked list
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

  // make it circular
  if (temp != NULL)
    temp->next = head;

  return head;
}

// traverse circular list
void printList(struct Node *head) {
  if (head == NULL)
    return;

  struct Node *temp = head;

  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node *head = createList(n);

  printList(head);

  return 0;
}