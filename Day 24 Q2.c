#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* removeElements(struct Node* head, int val) {
    while (head && head->data == val) {
        struct Node* t = head;
        head = head->next;
        free(t);
    }

    struct Node* curr = head;

    while (curr && curr->next) {
        if (curr->next->data == val) {
            struct Node* t = curr->next;
            curr->next = t->next;
            free(t);
        } else {
            curr = curr->next;
        }
    }
    return head;
}
