/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    int maxLen = 0;

    /* Hash map simulation */
    int hash[2001];  // range for prefix sum
    for (int i = 0; i < 2001; i++)
        hash[i] = -2;   // -2 means not visited

    /* Important: prefix sum = 0 at index -1 */
    hash[1000] = -1;   // shift by +1000

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int idx = prefix + 1000;

        if (hash[idx] != -2) {
            int len = i - hash[idx];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[idx] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}