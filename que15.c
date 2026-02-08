/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32*/

#include <stdio.h>

// Recursive function to compute a^b
int power(int a, int b)
{
    // Base case: anything power 0 = 1
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main()
{
    int a, b;

    // Input a and b
    scanf("%d %d", &a, &b);

    // Call function and print result
    printf("%d", power(a, b));

    return 0;
}
