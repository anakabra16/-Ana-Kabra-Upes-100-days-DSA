#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int calculate(char *s) {
  int n = strlen(s);
  int *stack = (int *)malloc(sizeof(int) * n);
  int top = -1;

  int num = 0;
  char sign = '+';

  for (int i = 0; s[i] != '\0'; i++) {

    if (isdigit(s[i])) {
      num = num * 10 + (s[i] - '0');
    }

    if ((!isdigit(s[i]) && s[i] != ' ') || s[i + 1] == '\0') {

      if (sign == '+')
        stack[++top] = num;
      else if (sign == '-')
        stack[++top] = -num;
      else if (sign == '*')
        stack[top] = stack[top] * num;
      else if (sign == '/')
        stack[top] = stack[top] / num;

      sign = s[i];
      num = 0;
    }
  }

  int result = 0;
  for (int i = 0; i <= top; i++) {
    result += stack[i];
  }

  free(stack);
  return result;
}