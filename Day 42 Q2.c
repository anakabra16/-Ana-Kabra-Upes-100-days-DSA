#include <stdlib.h>

#define HEAP_SIZE 50000

typedef struct {
  int maxHeap[HEAP_SIZE]; // left (max heap)
  int minHeap[HEAP_SIZE]; // right (min heap)
  int sizeMax;
  int sizeMin;
} MedianFinder;

// ---------- SWAP ----------
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// ---------- MAX HEAP ----------
void maxHeapifyUp(MedianFinder *obj, int i) {
  while (i > 0) {
    int p = (i - 1) / 2;
    if (obj->maxHeap[p] < obj->maxHeap[i]) {
      swap(&obj->maxHeap[p], &obj->maxHeap[i]);
      i = p;
    } else
      break;
  }
}

void maxHeapifyDown(MedianFinder *obj, int i) {
  while (1) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;

    if (l < obj->sizeMax && obj->maxHeap[l] > obj->maxHeap[largest])
      largest = l;
    if (r < obj->sizeMax && obj->maxHeap[r] > obj->maxHeap[largest])
      largest = r;

    if (largest != i) {
      swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
      i = largest;
    } else
      break;
  }
}

// ---------- MIN HEAP ----------
void minHeapifyUp(MedianFinder *obj, int i) {
  while (i > 0) {
    int p = (i - 1) / 2;
    if (obj->minHeap[p] > obj->minHeap[i]) {
      swap(&obj->minHeap[p], &obj->minHeap[i]);
      i = p;
    } else
      break;
  }
}

void minHeapifyDown(MedianFinder *obj, int i) {
  while (1) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int smallest = i;

    if (l < obj->sizeMin && obj->minHeap[l] < obj->minHeap[smallest])
      smallest = l;
    if (r < obj->sizeMin && obj->minHeap[r] < obj->minHeap[smallest])
      smallest = r;

    if (smallest != i) {
      swap(&obj->minHeap[i], &obj->minHeap[smallest]);
      i = smallest;
    } else
      break;
  }
}

// ---------- CREATE ----------
MedianFinder *medianFinderCreate() {
  MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
  obj->sizeMax = 0;
  obj->sizeMin = 0;
  return obj;
}

// ---------- ADD ----------
void medianFinderAddNum(MedianFinder *obj, int num) {

  // Step 1: push to max heap
  obj->maxHeap[obj->sizeMax] = num;
  maxHeapifyUp(obj, obj->sizeMax);
  obj->sizeMax++;

  // Step 2: move max → min
  int val = obj->maxHeap[0];
  obj->maxHeap[0] = obj->maxHeap[obj->sizeMax - 1];
  obj->sizeMax--;
  maxHeapifyDown(obj, 0);

  obj->minHeap[obj->sizeMin] = val;
  minHeapifyUp(obj, obj->sizeMin);
  obj->sizeMin++;

  // Step 3: balance
  if (obj->sizeMin > obj->sizeMax) {
    int v = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[obj->sizeMin - 1];
    obj->sizeMin--;
    minHeapifyDown(obj, 0);

    obj->maxHeap[obj->sizeMax] = v;
    maxHeapifyUp(obj, obj->sizeMax);
    obj->sizeMax++;
  }
}

// ---------- FIND MEDIAN ----------
double medianFinderFindMedian(MedianFinder *obj) {
  if (obj->sizeMax > obj->sizeMin)
    return obj->maxHeap[0];

  return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

// ---------- FREE ----------
void medianFinderFree(MedianFinder *obj) { free(obj); }