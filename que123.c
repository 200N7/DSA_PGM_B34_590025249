/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *left, *right;
};

/* Create new node */
struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

/* Build tree from level order array */
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

/* Count total nodes */
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* Check complete binary tree */
int isComplete(struct Node* root, int index, int total) {
    if (root == NULL)
        return 1;

    if (index >= total)
        return 0;

    return isComplete(root->left, 2*index + 1, total) &&
           isComplete(root->right, 2*index + 2, total);
}

/* Check Min Heap property */
int isMinHeap(struct Node* root) {
    /* Leaf node */
    if (root->left == NULL && root->right == NULL)
        return 1;

    /* Only left child */
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    /* Both children */
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    int total = countNodes(root);

    if (isComplete(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}