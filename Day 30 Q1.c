#include <stdio.h>
#include <stdlib.h>

struct Node {
  int coeff;
  int exp;
  struct Node *next;
};

// create polynomial
struct Node *createPoly(int n) {
  struct Node *head = NULL, *temp = NULL, *newNode;

  for (int i = 0; i < n; i++) {
    int c, e;
    scanf("%d %d", &c, &e);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
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

// print polynomial
void printPoly(struct Node *head) {
  while (head != NULL) {

    // print coefficient
    printf("%d", head->coeff);

    // print variable part
    if (head->exp > 1)
      printf("x^%d", head->exp);
    else if (head->exp == 1)
      printf("x");

    // print + if not last node
    if (head->next != NULL)
      printf(" + ");

    head = head->next;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node *poly = createPoly(n);

  printPoly(poly);

  return 0;
}