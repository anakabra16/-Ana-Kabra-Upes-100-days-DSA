#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

int main() {
  int n;
  scanf("%d", &n);

  struct Node *head = NULL, *temp = NULL, *newNode;

  // create linked list
  for (int i = 0; i < n; i++) {
    int value;
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }

  // count nodes
  int count = 0;
  temp = head;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  printf("%d\n", count);

  return 0;
}