#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeCycle(struct Node* head) {

    struct Node *slow = head, *fast = head;

    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // No cycle
    if (slow != fast)
        return;

    // Find start of cycle
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Find last node of cycle
    while (fast->next != slow) {
        fast = fast->next;
    }

    // Remove cycle
    fast->next = NULL;
}