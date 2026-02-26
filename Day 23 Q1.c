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

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node d, *t = &d;
    d.next = NULL;

    while (a && b) {
        if (a->data <= b->data) { t->next = a; a = a->next; }
        else { t->next = b; b = b->next; }
        t = t->next;
    }
    t->next = a ? a : b;
    return d.next;
}

void print(struct Node* h) {
    while (h) { printf("%d ", h->data); h = h->next; }
}

int main() {
    int n,m,x;
    struct Node *l1=NULL,*l2=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){ scanf("%d",&x); l1=insert(l1,x); }

    scanf("%d",&m);
    for(int i=0;i<m;i++){ scanf("%d",&x); l2=insert(l2,x); }

    print(merge(l1,l2));
}