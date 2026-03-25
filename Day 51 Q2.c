#include <stdio.h>
#include <stdlib.h>

// Tree Node definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;  // LCA found
    }
    return NULL;
}

// Search node by value (to get pointer for p and q)
struct TreeNode* search(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val)
            return root;
        else if (val < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main() {
    int n, x, p_val, q_val;
    struct TreeNode* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST values
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Input p and q
    scanf("%d %d", &p_val, &q_val);

    // Find nodes
    struct TreeNode* p = search(root, p_val);
    struct TreeNode* q = search(root, q_val);

    // Find LCA
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Output
    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}