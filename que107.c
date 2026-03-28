/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* createNode(int val){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=val; n->left=n->right=NULL;
    return n;
}

struct Node* buildTree(int arr[],int n,int i){
    if(i>=n || arr[i]==-1) return NULL;
    struct Node* root=createNode(arr[i]);
    root->left=buildTree(arr,n,2*i+1);
    root->right=buildTree(arr,n,2*i+2);
    return root;
}

/* LCA for normal binary tree */
struct Node* LCA(struct Node* root,int n1,int n2){
    if(root==NULL) return NULL;

    if(root->data==n1 || root->data==n2)
        return root;

    struct Node* left = LCA(root->left,n1,n2);
    struct Node* right = LCA(root->right,n1,n2);

    if(left && right) return root;

    return left ? left : right;
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int n1,n2;
    scanf("%d %d",&n1,&n2);

    struct Node* root=buildTree(arr,n,0);
    struct Node* ans=LCA(root,n1,n2);

    if(ans) printf("%d",ans->data);
}