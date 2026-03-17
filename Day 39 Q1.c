#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(int i){
    while(i>0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x){
    heap[size] = x;
    heapifyUp(size);
    size++;
}

void extractMin(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
}

void peek(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
}

int main(){

    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i=0;i<n;i++){

        scanf("%s", op);

        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin")==0){
            extractMin();
        }
        else if(strcmp(op,"peek")==0){
            peek();
        }
    }

    return 0;
}