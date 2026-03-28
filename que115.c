/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/

#include <stdio.h>
#include <stdlib.h>

/* Tree node structure */
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

/* Build tree from level-order array */
struct Node* buildTree(int arr[], int n, int index)
{
    if(index >= n || arr[index] == -1)
        return NULL;

    struct Node* root = createNode(arr[index]);

    root->left = buildTree(arr, n, 2*index + 1);
    root->right = buildTree(arr, n, 2*index + 2);

    return root;
}

/* Check if two trees are mirror */
int isMirror(struct Node* t1, struct Node* t2)
{
    /* Both NULL → symmetric */
    if(t1 == NULL && t2 == NULL)
        return 1;

    /* One NULL → not symmetric */
    if(t1 == NULL || t2 == NULL)
        return 0;

    /* Check data and mirror condition */
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

/* Check symmetric tree */
int isSymmetric(struct Node* root)
{
    if(root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if(isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}