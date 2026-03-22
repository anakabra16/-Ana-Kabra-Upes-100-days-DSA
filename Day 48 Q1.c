#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    // If both children are NULL → leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Build tree using level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    int leafCount = countLeafNodes(root);

    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}