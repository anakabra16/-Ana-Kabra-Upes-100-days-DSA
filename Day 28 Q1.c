#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, x;
    struct Node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &x);

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

    // make circular
    temp->next = head;

    // traversal
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}
