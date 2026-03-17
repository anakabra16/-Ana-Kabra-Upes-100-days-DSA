#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

int main() {
    int n, c, e;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = c;
        newnode->exp = e;
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

    temp = head;

    while(temp != NULL) {
        if(temp->exp == 0)
            printf("%d", temp->coeff);
        else if(temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}