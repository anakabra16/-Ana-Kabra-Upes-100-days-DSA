#include <stdio.h>
#include <stdlib.h>

// Node for linked list bucket
struct Node {
  float value;
  struct Node *next;
};

// Insert in sorted order (Insertion Sort in bucket)
void insertSorted(struct Node **head, float val) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->value = val;
  newNode->next = NULL;

  if (*head == NULL || (*head)->value >= val) {
    newNode->next = *head;
    *head = newNode;
  } else {
    struct Node *curr = *head;
    while (curr->next != NULL && curr->next->value < val) {
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  float arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%f", &arr[i]);
  }

  // Create buckets
  struct Node *buckets[n];
  for (int i = 0; i < n; i++) {
    buckets[i] = NULL;
  }

  // Step 1: Distribute elements
  for (int i = 0; i < n; i++) {
    int index = (int)(n * arr[i]);
    insertSorted(&buckets[index], arr[i]);
  }

  // Step 2: Concatenate buckets
  int k = 0;
  for (int i = 0; i < n; i++) {
    struct Node *curr = buckets[i];
    while (curr != NULL) {
      arr[k++] = curr->value;
      curr = curr->next;
    }
  }

  // Print sorted array
  for (int i = 0; i < n; i++) {
    printf("%.2f ", arr[i]);
  }

  return 0;
}