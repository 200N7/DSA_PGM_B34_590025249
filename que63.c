/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>

#define MAX 100   // Maximum stack size

int stack[MAX];
int top = -1;     // Stack initially empty

/* Function to push element */
void push(int value) {
    if(top < MAX - 1) {      // Check overflow
        stack[++top] = value;
    }
}

/* Function to pop element */
void pop() {
    if(top >= 0) {           // Check underflow
        top--;               // Just decrease top
    }
}

int main() {

    int n;
    scanf("%d", &n);    // Number of elements to push

    // Push n elements
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    int m;
    scanf("%d", &m);    // Number of pops

    // Perform m pop operations
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining elements from top to bottom
    for(int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if(i != 0)
            printf(" ");
    }

    return 0;
}