#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 1000
#define LEN 50

// comparator for sorting strings
int cmp(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }

int main() {
  int n;
  scanf("%d", &n);

  char names[MAX][LEN];

  for (int i = 0; i < n; i++) {
    scanf("%s", names[i]);
  }

  // sort names
  qsort(names, n, sizeof(names[0]), cmp);

  char winner[LEN];
  int maxVotes = 0;

  int count = 1;

  for (int i = 1; i <= n; i++) {
    if (i < n && strcmp(names[i], names[i - 1]) == 0) {
      count++;
    } else {
      // new candidate block
      if (count > maxVotes) {
        maxVotes = count;
        strcpy(winner, names[i - 1]);
      }
      count = 1;
    }
  }

  printf("%s %d", winner, maxVotes);

  return 0;
}