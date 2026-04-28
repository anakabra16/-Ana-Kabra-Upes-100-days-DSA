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

// rotate list
struct Node *rotateRight(struct Node *head, int k) {
  if (head == NULL || head->next == NULL)
    return head;

  // Step 1: find length and last node
  int n = 1;
  struct Node *temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
    n++;
  }

  // Step 2: handle large k
  k = k % n;
  if (k == 0)
    return head;

  // Step 3: make circular
  temp->next = head;

  // Step 4: move to (n - k)th node
  int steps = n - k;
  struct Node *newTail = head;

  for (int i = 1; i < steps; i++) {
    newTail = newTail->next;
  }

  // Step 5: break loop
  struct Node *newHead = newTail->next;
  newTail->next = NULL;

  return newHead;
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

  int k;
  scanf("%d", &k);

  head = rotateRight(head, k);

  printList(head);

  return 0;
}