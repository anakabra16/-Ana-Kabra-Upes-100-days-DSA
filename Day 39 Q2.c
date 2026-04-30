#include <stdlib.h>

typedef struct {
  int num;
  int freq;
} Pair;

void swap(Pair *a, Pair *b) {
  Pair t = *a;
  *a = *b;
  *b = t;
}

void heapifyUp(Pair *heap, int i) {
  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap[p].freq > heap[i].freq) {
      swap(&heap[p], &heap[i]);
      i = p;
    } else
      break;
  }
}

void heapifyDown(Pair *heap, int size, int i) {
  while (1) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < size && heap[l].freq < heap[smallest].freq)
      smallest = l;
    if (r < size && heap[r].freq < heap[smallest].freq)
      smallest = r;

    if (smallest != i) {
      swap(&heap[i], &heap[smallest]);
      i = smallest;
    } else
      break;
  }
}

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {

  int offset = 10000;
  int freq[20001] = {0};

  // count frequency
  for (int i = 0; i < numsSize; i++)
    freq[nums[i] + offset]++;

  Pair *heap = (Pair *)malloc(sizeof(Pair) * k);
  int size = 0;

  for (int i = 0; i < 20001; i++) {
    if (freq[i] > 0) {

      Pair p = {i - offset, freq[i]};

      if (size < k) {
        heap[size] = p;
        heapifyUp(heap, size);
        size++;
      } else if (p.freq > heap[0].freq) {
        heap[0] = p;
        heapifyDown(heap, size, 0);
      }
    }
  }

  int *result = (int *)malloc(sizeof(int) * k);
  for (int i = 0; i < k; i++)
    result[i] = heap[i].num;

  *returnSize = k;
  return result;
}