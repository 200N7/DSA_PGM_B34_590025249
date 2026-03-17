/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/

#include <stdio.h>
#include <stdlib.h>

/* Structure for tree node */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Build tree from level order array */
struct Node* buildTree(int arr[], int n, int index)
{
    if(index >= n || arr[index] == -1)
        return NULL;

    struct Node* root = createNode(arr[index]);

    root->left = buildTree(arr, n, 2*index + 1);
    root->right = buildTree(arr, n, 2*index + 2);

    return root;
}

/* Function to calculate height of tree */
int height(struct Node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    /* Return maximum + 1 (for current node) */
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    /* Input level order traversal */
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* Build tree */
    struct Node* root = buildTree(arr, n, 0);

    /* Print height */
    printf("%d", height(root));

    return 0;
}