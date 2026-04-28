#include <stdio.h>
#include <string.h>

int main() {
  char s[1000];
  scanf("%s", s);

  int i = 0;
  int j = strlen(s) - 1;

  int isPalindrome = 1;

  while (i < j) {
    if (s[i] != s[j]) {
      isPalindrome = 0;
      break;
    }
    i++;
    j--;
  }

  if (isPalindrome)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}