/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node{
    int data;
    struct Node *left,*right;
};

struct Pair{
    struct Node* node;
    int hd;
};

struct Pair queue[MAX];
int front=0,rear=-1;

struct Node* createNode(int val){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=val; n->left=n->right=NULL;
    return n;
}

void enqueue(struct Node* n,int hd){
    queue[++rear].node=n;
    queue[rear].hd=hd;
}

struct Pair dequeue(){
    return queue[front++];
}

int isEmpty(){ return front>rear; }

struct Node* buildTree(int arr[],int n,int i){
    if(i>=n || arr[i]==-1) return NULL;
    struct Node* root=createNode(arr[i]);
    root->left=buildTree(arr,n,2*i+1);
    root->right=buildTree(arr,n,2*i+2);
    return root;
}

void verticalOrder(struct Node* root){
    int map[200][200]={0}, count[200]={0};

    enqueue(root,100);

    while(!isEmpty()){
        struct Pair p = dequeue();
        int hd = p.hd;

        map[hd][count[hd]++] = p.node->data;

        if(p.node->left) enqueue(p.node->left,hd-1);
        if(p.node->right) enqueue(p.node->right,hd+1);
    }

    for(int i=0;i<200;i++){
        if(count[i]){
            for(int j=0;j<count[i];j++)
                printf("%d ",map[i][j]);
            printf("\n");
        }
    }
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n,0);
    verticalOrder(root);
}