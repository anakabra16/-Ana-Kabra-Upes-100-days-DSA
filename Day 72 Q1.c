#include <stdio.h>
#include <string.h>

int main() {
  char s[1000];
  scanf("%s", s);

  int visited[26] = {0}; // for lowercase letters

  for (int i = 0; s[i] != '\0'; i++) {
    int idx = s[i] - 'a';

    if (visited[idx]) {
      printf("%c", s[i]);
      return 0;
    }

    visited[idx] = 1;
  }

  printf("-1");
  return 0;
}