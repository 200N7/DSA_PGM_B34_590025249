/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

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

/* Search element in inorder */
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

/* Build tree using inorder + postorder */
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex) {
    
    /* Base case */
    if (start > end)
        return NULL;

    /* Step 1: pick root from postorder (last element) */
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(curr);

    /* If leaf node */
    if (start == end)
        return root;

    /* Step 2: find root in inorder */
    int pos = search(inorder, start, end, curr);

    /* Step 3: IMPORTANT → build RIGHT first */
    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

/* Preorder traversal */
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    /* Print preorder */
    preorder(root);

    return 0;
}