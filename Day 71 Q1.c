#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int size;

// initialize table
void init() {
  for (int i = 0; i < size; i++)
    table[i] = -1; // -1 means empty
}

// insert
void insert(int key) {
  int h = key % size;

  for (int i = 0; i < size; i++) {
    int idx = (h + i * i) % size;

    if (table[idx] == -1) {
      table[idx] = key;
      return;
    }
  }
}

// search
void search(int key) {
  int h = key % size;

  for (int i = 0; i < size; i++) {
    int idx = (h + i * i) % size;

    if (table[idx] == key) {
      printf("FOUND\n");
      return;
    }

    if (table[idx] == -1) {
      printf("NOT FOUND\n");
      return;
    }
  }

  printf("NOT FOUND\n");
}

int main() {
  int n;
  scanf("%d", &size); // table size
  scanf("%d", &n);    // number of operations

  init();

  char op[10];
  int key;

  for (int i = 0; i < n; i++) {
    scanf("%s %d", op, &key);

    if (strcmp(op, "INSERT") == 0) {
      insert(key);
    } else if (strcmp(op, "SEARCH") == 0) {
      search(key);
    }
  }

  return 0;
}