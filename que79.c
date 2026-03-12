/*Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the 
maximum element and place it at the end of the array.*/

#include <stdio.h>

/* Function to swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify a subtree rooted with index i
   n is size of heap */
void heapify(int arr[], int n, int i)
{
    int largest = i;        // Assume root is largest
    int left = 2*i + 1;     // Left child
    int right = 2*i + 2;    // Right child

    /* If left child is larger than root */
    if(left < n && arr[left] > arr[largest])
        largest = left;

    /* If right child is larger than largest so far */
    if(right < n && arr[right] > arr[largest])
        largest = right;

    /* If largest is not root */
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);

        /* Recursively heapify the affected subtree */
        heapify(arr, n, largest);
    }
}

/* Heap Sort Function */
void heapSort(int arr[], int n)
{
    /* Step 1: Build Max Heap */
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    /* Step 2: Extract elements from heap one by one */
    for(int i = n-1; i >= 0; i--)
    {
        /* Move current root to end */
        swap(&arr[0], &arr[i]);

        /* call heapify on the reduced heap */
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    /* Read size of array */
    scanf("%d", &n);

    int arr[n];

    /* Read array elements */
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* Perform heap sort */
    heapSort(arr, n);

    /* Print sorted array */
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}