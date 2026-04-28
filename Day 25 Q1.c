#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

// create linked list
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

// count occurrences
int countOccurrences(struct Node *head, int key) {
  int count = 0;

  while (head != NULL) {
    if (head->data == key)
      count++;
    head = head->next;
  }

  return count;
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node *head = createList(n);

  int key;
  scanf("%d", &key);

  int result = countOccurrences(head, key);

  printf("%d\n", result);

  return 0;
}