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

/* Build tree from level-order (-1 = NULL) */
struct Node* buildTree(int arr[], int n) {

    if(n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n) {

        struct Node* curr = queue[front++];

        if(arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

/* Calculate height */
int maxDepth(struct Node* root) {
    if(root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    printf("%d", maxDepth(root));

    return 0;
}