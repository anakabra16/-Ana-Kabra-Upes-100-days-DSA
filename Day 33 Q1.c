#include <ctype.h>
#include <stdio.h>


#define MAX 100

char stack[MAX];
int top = -1;

// push
void push(char c) { stack[++top] = c; }

// pop
char pop() { return stack[top--]; }

// peek
char peek() { return stack[top]; }

// precedence
int precedence(char c) {
  if (c == '^')
    return 3;
  if (c == '*' || c == '/')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return 0;
}

int main() {
  char exp[100], result[100];
  int k = 0;

  scanf("%s", exp);

  for (int i = 0; exp[i] != '\0'; i++) {
    char ch = exp[i];

    // operand
    if (isalnum(ch)) {
      result[k++] = ch;
    }

    // opening bracket
    else if (ch == '(') {
      push(ch);
    }

    // closing bracket
    else if (ch == ')') {
      while (top != -1 && peek() != '(') {
        result[k++] = pop();
      }
      pop(); // remove '('
    }

    // operator
    else {
      while (top != -1 && precedence(peek()) >= precedence(ch)) {
        result[k++] = pop();
      }
      push(ch);
    }
  }

  // pop remaining operators
  while (top != -1) {
    result[k++] = pop();
  }

  result[k] = '\0';

  printf("%s\n", result);

  return 0;
}