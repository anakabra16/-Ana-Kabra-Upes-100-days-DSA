#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue structure (node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

// Queue
struct QNode queue[1000];
int front = -1, rear = -1;

void enqueue(struct Node* node, int hd) {
    queue[++rear].node = node;
    queue[rear].hd = hd;
}

struct QNode dequeue() {
    return queue[++front];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* q[1000];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // HD range storage
    int minHD = 0, maxHD = 0;

    // Temporary storage: hd → list of values
    int map[2000][100]; // simple 2D storage
    int count[2000] = {0};

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd + 1000; // shift index to avoid negative

        // Store node
        map[hd][count[hd]++] = curr->data;

        if (hd - 1000 < minHD) minHD = hd - 1000;
        if (hd - 1000 > maxHD) maxHD = hd - 1000;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);

        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 1000;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}