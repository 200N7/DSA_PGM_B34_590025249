/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int visited[n];   // Marks elements already counted

    // Initialize visited array to 0
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    // Input array
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Count frequency
    for(int i = 0; i < n; i++) {

        // Skip if already counted
        if(visited[i] == 1)
            continue;

        int count = 1;

        // Compare with remaining elements
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;   // Mark duplicate as counted
            }
        }

        // Print element and its count
        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
