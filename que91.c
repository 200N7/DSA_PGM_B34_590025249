/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure for tree node */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Queue for level order traversal */
struct Node* queue[MAX];
int front = 0, rear = -1;

/* Create new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Enqueue */
void enqueue(struct Node* node)
{
    queue[++rear] = node;
}

/* Dequeue */
struct Node* dequeue()
{
    return queue[front++];
}

/* Check if queue is empty */
int isEmpty()
{
    return front > rear;
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

/* Level Order Traversal */
void levelOrder(struct Node* root)
{
    if(root == NULL)
        return;

    enqueue(root);

    while(!isEmpty())
    {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left != NULL)
            enqueue(temp->left);

        if(temp->right != NULL)
            enqueue(temp->right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    /* Input level order */
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    /* Print level order traversal */
    levelOrder(root);

    return 0;
}