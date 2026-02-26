#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* insertEnd(struct Node* head, int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    n->prev = NULL;

    if (!head) return n;

    struct Node* p = head;
    while (p->next) p = p->next;

    p->next = n;
    n->prev = p;
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    printList(head);
}