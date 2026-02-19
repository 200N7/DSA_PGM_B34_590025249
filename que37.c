/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>
#include <stdlib.h>   // for qsort
#include <math.h>     // for abs

// compare function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 1: sort the array
    qsort(arr, n, sizeof(int), compare);

    // Step 2: two pointer technique
    int left = 0;
    int right = n - 1;

    int minSum = 1000000000;   // large value
    int a, b;

    while(left < right) {
        int sum = arr[left] + arr[right];

        // Update closest sum
        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            a = arr[left];
            b = arr[right];
        }

        // Move pointers
        if(sum < 0)
            left++;      // need larger value
        else
            right--;     // need smaller value
    }

    printf("%d %d", a, b);

    return 0;
}
