#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct Node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {

    /* Example Tree
           1
            \
             2
            /
           3
    */

    struct Node* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Preorder Traversal:\n");
    preorder(root);

    return 0;
}