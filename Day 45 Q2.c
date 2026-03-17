#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int maxDepth(struct Node* root) {

    if(root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

int main() {

    /* Example tree
            3
           / \
          9  20
             / \
            15  7
    */

    struct Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("Maximum Depth: %d", maxDepth(root));

    return 0;
}