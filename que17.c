/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/

#include <stdio.h>

// recursive function to print string in reverse
void mirror(char str[], int index)
{
    // base case: end of string reached
    if (str[index] == '\0')
        return;

    // go forward first
    mirror(str, index + 1);

    // print while coming back (reverse order)
    printf("%c", str[index]);
}

int main()
{
    char str[100];

    // read string
    scanf("%s", str);

    // call recursive function
    mirror(str, 0);

    return 0;
}
