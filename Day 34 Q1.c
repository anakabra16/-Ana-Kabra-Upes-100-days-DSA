#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Node for stack
struct Node {
  int data;
  struct Node *next;
};

// push
void push(struct Node **top, int val) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = *top;
  *top = newNode;
}

// pop
int pop(struct Node **top) {
  if (*top == NULL)
    return 0;

  struct Node *temp = *top;
  int val = temp->data;
  *top = temp->next;
  free(temp);
  return val;
}

int main() {
  char exp[100];
  fgets(exp, sizeof(exp), stdin);

  struct Node *stack = NULL;

  char *token = strtok(exp, " \n");

  while (token != NULL) {

    // if number
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      push(&stack, atoi(token));
    } else {
      int b = pop(&stack);
      int a = pop(&stack);
      int result;

      if (strcmp(token, "+") == 0)
        result = a + b;
      else if (strcmp(token, "-") == 0)
        result = a - b;
      else if (strcmp(token, "*") == 0)
        result = a * b;
      else
        result = a / b;

      push(&stack, result);
    }

    token = strtok(NULL, " \n");
  }

  printf("%d\n", pop(&stack));

  return 0;
}