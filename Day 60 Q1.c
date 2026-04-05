#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check complete binary tree
int isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check heap property
int isHeap(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->right == NULL)
        return (root->data <= root->left->data) && isHeap(root->left);

    else {
        if (root->data <= root->left->data &&
            root->data <= root->right->data)
            return isHeap(root->left) && isHeap(root->right);
        else
            return 0;
    }
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}