/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for a node */
struct Node
{
    int data;
    struct Node *next;
};

/* Front and rear pointers of queue */
struct Node *front = NULL;
struct Node *rear = NULL;

/* Enqueue operation (insert at rear) */
void enqueue(int value)
{
    /* Create new node */
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    /* If queue is empty */
    if(rear == NULL)
    {
        front = rear = newNode;
        return;
    }

    /* Add node at the end */
    rear->next = newNode;
    rear = newNode;
}

/* Dequeue operation (remove from front) */
void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node *temp = front;

    /* Print removed element */
    printf("%d\n", front->data);

    front = front->next;

    /* If queue becomes empty */
    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        char op[20];
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0)
        {
            int x;
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0)
        {
            dequeue();
        }
    }

    return 0;
}