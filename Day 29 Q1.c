#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){

    int n, k, x;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d",&n);

    // create linked list
    for(int i=0;i<n;i++){
        scanf("%d",&x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d",&k);

    // find length
    int count = 1;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }

    // connect last node to head (make circular)
    temp->next = head;

    k = k % count;

    // move to new last node
    int steps = count - k;
    temp = head;
    for(int i=1;i<steps;i++)
        temp = temp->next;

    // new head
    head = temp->next;

    // break circle
    temp->next = NULL;

    // print list
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    return 0;
}