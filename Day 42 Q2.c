#include <stdlib.h>

typedef struct {
    int maxHeap[50000];
    int minHeap[50000];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

/* ---------- MAX HEAP ---------- */

void maxHeapifyUp(MedianFinder* obj,int i){
    while(i>0){
        int p=(i-1)/2;
        if(obj->maxHeap[p] >= obj->maxHeap[i]) break;
        swap(&obj->maxHeap[p],&obj->maxHeap[i]);
        i=p;
    }
}

void maxHeapifyDown(MedianFinder* obj,int i){
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;

        if(l<obj->maxSize && obj->maxHeap[l] > obj->maxHeap[largest])
            largest=l;

        if(r<obj->maxSize && obj->maxHeap[r] > obj->maxHeap[largest])
            largest=r;

        if(largest==i) break;

        swap(&obj->maxHeap[i],&obj->maxHeap[largest]);
        i=largest;
    }
}

void maxPush(MedianFinder* obj,int val){
    obj->maxHeap[obj->maxSize]=val;
    maxHeapifyUp(obj,obj->maxSize++);
}

int maxPop(MedianFinder* obj){
    int root=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];
    maxHeapifyDown(obj,0);
    return root;
}

/* ---------- MIN HEAP ---------- */

void minHeapifyUp(MedianFinder* obj,int i){
    while(i>0){
        int p=(i-1)/2;
        if(obj->minHeap[p] <= obj->minHeap[i]) break;
        swap(&obj->minHeap[p],&obj->minHeap[i]);
        i=p;
    }
}

void minHeapifyDown(MedianFinder* obj,int i){
    while(1){
        int l=2*i+1,r=2*i+2,smallest=i;

        if(l<obj->minSize && obj->minHeap[l] < obj->minHeap[smallest])
            smallest=l;

        if(r<obj->minSize && obj->minHeap[r] < obj->minHeap[smallest])
            smallest=r;

        if(smallest==i) break;

        swap(&obj->minHeap[i],&obj->minHeap[smallest]);
        i=smallest;
    }
}

void minPush(MedianFinder* obj,int val){
    obj->minHeap[obj->minSize]=val;
    minHeapifyUp(obj,obj->minSize++);
}

int minPop(MedianFinder* obj){
    int root=obj->minHeap[0];
    obj->minHeap[0]=obj->minHeap[--obj->minSize];
    minHeapifyDown(obj,0);
    return root;
}

/* ---------- MEDIAN FINDER ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj=malloc(sizeof(MedianFinder));
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {

    if(obj->maxSize==0 || num <= obj->maxHeap[0])
        maxPush(obj,num);
    else
        minPush(obj,num);

    /* balance heaps */

    if(obj->maxSize > obj->minSize + 1)
        minPush(obj,maxPop(obj));

    else if(obj->minSize > obj->maxSize)
        maxPush(obj,minPop(obj));
}

double findMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}