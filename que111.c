/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* queue[MAX];
int front=0,rear=-1;

struct Node* createNode(int val){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=val; n->left=n->right=NULL;
    return n;
}

void enqueue(struct Node* n){ queue[++rear]=n; }
struct Node* dequeue(){ return queue[front++]; }
int isEmpty(){ return front>rear; }

struct Node* buildTree(int arr[],int n,int i){
    if(i>=n || arr[i]==-1) return NULL;
    struct Node* root=createNode(arr[i]);
    root->left=buildTree(arr,n,2*i+1);
    root->right=buildTree(arr,n,2*i+2);
    return root;
}

void zigzag(struct Node* root){
    if(!root) return;

    int leftToRight = 1;
    enqueue(root);

    while(!isEmpty()){
        int size = rear-front+1;
        int temp[size];

        for(int i=0;i<size;i++){
            struct Node* node=dequeue();

            int index = leftToRight ? i : size-i-1;
            temp[index] = node->data;

            if(node->left) enqueue(node->left);
            if(node->right) enqueue(node->right);
        }

        for(int i=0;i<size;i++)
            printf("%d ", temp[i]);

        leftToRight = !leftToRight;
    }
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n,0);
    zigzag(root);
}