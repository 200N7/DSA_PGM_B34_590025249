/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/

#include <stdio.h>
#include <stdlib.h>

/* Define structure for tree node */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Function to create a new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to build tree from level order array */
struct Node* buildTree(int arr[], int n, int index)
{
    if(index >= n || arr[index] == -1)
        return NULL;

    struct Node* root = createNode(arr[index]);

    /* Left child */
    root->left = buildTree(arr, n, 2*index + 1);

    /* Right child */
    root->right = buildTree(arr, n, 2*index + 2);

    return root;
}

/* Inorder Traversal */
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
    scanf("%d",&n);

    int arr[n];

    /* Read level order elements */
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    /* Construct tree */
    struct Node* root = buildTree(arr, n, 0);

    /* Print inorder traversal */
    inorder(root);

    return 0;
}