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

struct Node* deleteKey(struct Node* head, int key) {
    if (!head) return head;

    if (head->data == key) {
        struct Node* t = head;
        head = head->next;
        free(t);
        return head;
    }

    struct Node* p = head;
    while (p->next && p->next->data != key)
        p = p->next;

    if (p->next) {
        struct Node* t = p->next;
        p->next = t->next;
        free(t);
    }
    return head;
}

void print(struct Node* h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
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
    head = deleteKey(head, key);
    print(head);
}