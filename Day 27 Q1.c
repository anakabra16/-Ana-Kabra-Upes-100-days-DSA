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

// get length
int getLength(struct Node *head) {
  int len = 0;
  while (head != NULL) {
    len++;
    head = head->next;
  }
  return len;
}

// find intersection (by value here)
int findIntersection(struct Node *l1, struct Node *l2) {
  int len1 = getLength(l1);
  int len2 = getLength(l2);

  // move longer list ahead
  while (len1 > len2) {
    l1 = l1->next;
    len1--;
  }
  while (len2 > len1) {
    l2 = l2->next;
    len2--;
  }

  // traverse both
  while (l1 != NULL && l2 != NULL) {
    if (l1->data == l2->data) {
      return l1->data; // intersection found
    }
    l1 = l1->next;
    l2 = l2->next;
  }

  return -1; // no intersection
}

int main() {
  int n, m;

  scanf("%d", &n);
  struct Node *list1 = createList(n);

  scanf("%d", &m);
  struct Node *list2 = createList(m);

  int result = findIntersection(list1, list2);

  if (result == -1)
    printf("No Intersection\n");
  else
    printf("%d\n", result);

  return 0;
}