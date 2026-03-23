/*Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

/* Structure for BST node */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert into BST */
struct Node* insert(struct Node* root, int value)
{
    /* If tree is empty */
    if(root == NULL)
        return createNode(value);

    /* Insert in left subtree */
    if(value < root->data)
        root->left = insert(root->left, value);

    /* Insert in right subtree */
    else
        root->right = insert(root->right, value);

    return root;
}

/* Inorder Traversal (sorted output) */
void inorder(struct Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    /* Insert elements */
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    /* Print inorder traversal */
    inorder(root);

    return 0;
}