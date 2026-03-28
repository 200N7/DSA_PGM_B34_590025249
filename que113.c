/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* queue[MAX];
int front = 0, rear = -1;

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

void enqueue(struct Node* n) { queue[++rear] = n; }
struct Node* dequeue() { return queue[front++]; }
int isEmpty() { return front > rear; }

/* Build tree */
struct Node* buildTree(int arr[], int n, int i) {
    if(i >= n || arr[i] == -1) return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i+1);
    root->right = buildTree(arr, n, 2*i+2);
    return root;
}

/* Right View */
void rightView(struct Node* root) {
    if(!root) return;

    enqueue(root);

    while(!isEmpty()) {
        int size = rear - front + 1;

        for(int i = 0; i < size; i++) {
            struct Node* temp = dequeue();

            /* last node of level */
            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left) enqueue(temp->left);
            if(temp->right) enqueue(temp->right);
        }
    }
}

int main() {
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr,n,0);
    rightView(root);
}