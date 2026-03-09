/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

/* Function to insert element into priority queue */
void insert(int value)
{
    if(size == MAX)
        return;

    pq[size++] = value;
}

/* Function to delete highest priority element (smallest value) */
void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int minIndex = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }

    printf("%d\n", pq[minIndex]);

    for(int i = minIndex; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

/* Function to peek highest priority element */
void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = pq[0];

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
            min = pq[i];
    }

    printf("%d\n", min);
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        char operation[10];
        scanf("%s", operation);

        if(strcmp(operation, "insert") == 0)
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(operation, "delete") == 0)
        {
            deleteElement();
        }
        else if(strcmp(operation, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}