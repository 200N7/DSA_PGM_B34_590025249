/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* Swap two numbers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify upward after insertion */
void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

/* Heapify downward after deletion */
void heapifyDown(int index)
{
    while(1)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

/* Insert element into heap */
void insert(int value)
{
    if(size == MAX)
        return;

    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* Return minimum element */
void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

/* Remove and print minimum element */
void extractMin()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        char op[20];
        scanf("%s", op);

        if(strcmp(op,"insert") == 0)
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }

        else if(strcmp(op,"peek") == 0)
        {
            peek();
        }

        else if(strcmp(op,"extractMin") == 0)
        {
            extractMin();
        }
    }

    return 0;
}