#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
  int *x = (int *)a;
  int *y = (int *)b;
  return x[0] - y[0];
}

// Min heap helper functions
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(int heap[], int i) {
  while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
    swap(&heap[i], &heap[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void heapifyDown(int heap[], int size, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && heap[left] < heap[smallest])
    smallest = left;
  if (right < size && heap[right] < heap[smallest])
    smallest = right;

  if (smallest != i) {
    swap(&heap[i], &heap[smallest]);
    heapifyDown(heap, size, smallest);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int intervals[n][2];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &intervals[i][0], &intervals[i][1]);
  }

  // Sort by start time
  qsort(intervals, n, sizeof(intervals[0]), compare);

  int heap[n];
  int size = 0;

  // Add first meeting end time
  heap[size++] = intervals[0][1];

  for (int i = 1; i < n; i++) {
    // If room free
    if (intervals[i][0] >= heap[0]) {
      heap[0] = intervals[i][1];
      heapifyDown(heap, size, 0);
    } else {
      // Need new room
      heap[size++] = intervals[i][1];
      heapifyUp(heap, size - 1);
    }
  }

  printf("%d", size);

  return 0;
}