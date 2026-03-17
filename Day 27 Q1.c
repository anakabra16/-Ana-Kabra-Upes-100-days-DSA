#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create linked list
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int val;

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Function to find length
int length(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct node *head1, struct node *head2) {

    int len1 = length(head1);
    int len2 = length(head2);

    struct node *p1 = head1;
    struct node *p2 = head2;

    int diff;

    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            p1 = p1->next;
    }
    else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    while(p1 != NULL && p2 != NULL) {
        if(p1->data == p2->data)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;
}

int main() {

    int n, m;

    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}