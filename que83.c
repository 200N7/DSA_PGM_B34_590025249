/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

int stack[MAX];
int top = -1;

/* Enqueue operation */
void enqueue(int value)
{
    rear++;
    queue[rear] = value;
}

/* Dequeue operation */
int dequeue()
{
    int value = queue[front];
    front++;
    return value;
}

/* Push into stack */
void push(int value)
{
    stack[++top] = value;
}

/* Pop from stack */
int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    /* Read number of elements */
    scanf("%d",&n);

    /* Read queue elements */
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        enqueue(x);
    }

    /* Step 1: Move queue elements to stack */
    for(int i=0;i<n;i++)
    {
        push(dequeue());
    }

    /* Step 2: Move stack elements back to queue */
    for(int i=0;i<n;i++)
    {
        enqueue(pop());
    }

    /* Print reversed queue */
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }

    return 0;
}