/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/

#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];
    int i = 0, j = 0, k = 0;

    // input size of first log
    scanf("%d", &p);

    // input first sorted array
    for (i = 0; i < p; i++)
        scanf("%d", &a[i]);

    // input size of second log
    scanf("%d", &q);

    // input second sorted array
    for (j = 0; j < q; j++)
        scanf("%d", &b[j]);

    i = 0;
    j = 0;

    // merge process
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // remaining elements of a
    while (i < p) {
        c[k] = a[i];
        i++;
        k++;
    }

    // remaining elements of b
    while (j < q) {
        c[k] = b[j];
        j++;
        k++;
    }

    // print merged array
    for (int t = 0; t < k; t++)
        printf("%d ", c[t]);

    return 0;
}
