#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

bool hasCycle(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}