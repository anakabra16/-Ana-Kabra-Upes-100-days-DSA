#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *head = NULL, *temp = NULL, *newnode;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = sum % 10;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } 
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}