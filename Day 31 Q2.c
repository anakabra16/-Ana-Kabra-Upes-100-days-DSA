#include <stdbool.h>

bool isValid(char *s) {
  char stack[10000];
  int top = -1;

  for (int i = 0; s[i] != '\0'; i++) {

    char ch = s[i];

    // push opening brackets
    if (ch == '(' || ch == '{' || ch == '[') {
      stack[++top] = ch;
    } else {
      // stack empty → invalid
      if (top == -1)
        return false;

      char topChar = stack[top--];

      // check matching
      if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') ||
          (ch == ']' && topChar != '[')) {
        return false;
      }
    }
  }

  // stack should be empty
  return (top == -1);
}