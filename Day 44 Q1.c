#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* ---------- Traversals ---------- */

void inorder(struct Node* root){
    if(root==NULL) return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root==NULL) return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

/* ---------- Build Tree from Level Order ---------- */

struct Node* buildTree(int arr[], int n){

    if(n==0 || arr[0]==-1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[n];
    int front=0, rear=0;

    queue[rear++] = root;

    int i=1;

    while(i<n){

        struct Node* current = queue[front++];

        if(arr[i] != -1){
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i<n && arr[i] != -1){
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr,n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}