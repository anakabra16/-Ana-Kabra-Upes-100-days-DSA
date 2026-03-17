#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// function to reverse a linked list
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// function to check palindrome
int isPalindrome(struct node *head) {

    if(head == NULL || head->next == NULL)
        return 1;

    struct node *slow = head, *fast = head;

    // find middle
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    struct node *second = reverse(slow->next);

    struct node *first = head;

    // compare both halves
    while(second != NULL) {
        if(first->data != second->data)
            return 0;

        first = first->next;
        second = second->next;
    }

    return 1;
}

int main() {

    int n, x;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    if(isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}