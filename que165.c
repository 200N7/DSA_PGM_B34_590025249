/*Problem: Implement Bubble Sort - Implement the algorithm.

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

    /* Bubble Sort */
    for (int i = 0; i < n - 1; i++) {

        int swapped = 0;  // optimization

        for (int j = 0; j < n - i - 1; j++) {

            /* Compare adjacent elements */
            if (arr[j] > arr[j + 1]) {

                /* Swap */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        /* If no swap happened → already sorted */
        if (swapped == 0)
            break;
    }

    /* Print sorted array */
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}