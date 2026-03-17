#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if(size < MAX) {
        pq[size++] = x;
    }
}

int findMinIndex() {
    if(size == 0)
        return -1;

    int minIndex = 0;

    for(int i = 1; i < size; i++) {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    return minIndex;
}

void deleteMin() {
    int index = findMinIndex();

    if(index == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);

    for(int i = index; i < size-1; i++) {
        pq[i] = pq[i+1];
    }

    size--;
}

void peek() {
    int index = findMinIndex();

    if(index == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);
}

int main() {

    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }

        else if(strcmp(op, "delete") == 0) {
            deleteMin();
        }

        else if(strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}