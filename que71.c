/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

/* Enqueue operation */
void enqueue(int value)
{
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

/* Dequeue operation */
int dequeue()
{
    int value = queue[front];
    front = (front + 1) % MAX;
    size--;
    return value;
}

/* Display queue from front to rear */
void display()
{
    for(int i = 0; i < size; i++)
    {
        int index = (front + i) % MAX;
        printf("%d", queue[index]);

        if(i != size - 1)
            printf(" ");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    /* Enqueue n elements */
    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    int m;
    scanf("%d", &m);

    /* Perform rotation m times */
    for(int i = 0; i < m; i++)
    {
        int x = dequeue();
        enqueue(x);
    }

    display();

    return 0;
}