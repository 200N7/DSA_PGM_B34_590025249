/*Problem: Implement Insertion Sort - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    /* Input array */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Insertion Sort */
    for (int i = 1; i < n; i++) {

        int key = arr[i];   // element to be inserted
        int j = i - 1;

        /* Shift elements greater than key to right */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        /* Insert key at correct position */
        arr[j + 1] = key;
    }

    /* Print sorted array */
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}