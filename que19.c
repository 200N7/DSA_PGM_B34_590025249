/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int left, right;

    // read string
    scanf("%s", s);

    // find last index
    right = strlen(s) - 1;
    left = 0;

    // two pointer comparison
    while (left < right)
    {
        if (s[left] != s[right])
        {
            printf("NO");
            return 0;
        }

        left++;
        right--;
    }

    printf("YES");
    return 0;
}
