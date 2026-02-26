#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

typedef struct{
    struct Node* head;
    int size;
} MyLinkedList;

struct Node* newNode(int v){
    struct Node* n=malloc(sizeof(struct Node));
    n->val=v; n->next=NULL;
    return n;
}

MyLinkedList* myLinkedListCreate(){
    MyLinkedList* o=malloc(sizeof(MyLinkedList));
    o->head=NULL; o->size=0;
    return o;
}

int get(MyLinkedList* o,int index){
    if(index<0||index>=o->size) return -1;
    struct Node* p=o->head;
    while(index--) p=p->next;
    return p->val;
}

void addAtHead(MyLinkedList* o,int v){
    struct Node* n=newNode(v);
    n->next=o->head; o->head=n; o->size++;
}

void addAtTail(MyLinkedList* o,int v){
    struct Node* n=newNode(v);
    if(!o->head) o->head=n;
    else{
        struct Node* p=o->head;
        while(p->next) p=p->next;
        p->next=n;
    }
    o->size++;
}

void addAtIndex(MyLinkedList* o,int index,int v){
    if(index<0||index>o->size) return;
    if(index==0){ addAtHead(o,v); return; }
    struct Node* p=o->head;
    for(int i=0;i<index-1;i++) p=p->next;
    struct Node* n=newNode(v);
    n->next=p->next; p->next=n; o->size++;
}

void deleteAtIndex(MyLinkedList* o,int index){
    if(index<0||index>=o->size) return;
    if(index==0){
        struct Node* t=o->head;
        o->head=t->next; free(t);
    }else{
        struct Node* p=o->head;
        for(int i=0;i<index-1;i++) p=p->next;
        struct Node* t=p->next;
        p->next=t->next; free(t);
    }
    o->size--;
}