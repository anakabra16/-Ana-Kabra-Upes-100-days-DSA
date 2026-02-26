#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int x) {
    struct Node* t = malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    return t;
}

struct Node* insert(struct Node* h, int x) {
    if (!h) return newNode(x);
    struct Node* p = h;
    while (p->next) p = p->next;
    p->next = newNode(x);
    return h;
}

int countKey(struct Node* head, int key) {
    int count = 0;
    while (head) {
        if (head->data == key) count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, x, key;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    scanf("%d", &key);
    printf("%d", countKey(head, key));
}