/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>   // For isalnum()
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Function to push an operator onto stack */
void push(char x) {
    stack[++top] = x;
}

/* Function to pop operator from stack */
char pop() {
    return stack[top--];
}

/* Function to check precedence of operators */
int precedence(char x) {

    if(x == '+' || x == '-')
        return 1;

    if(x == '*' || x == '/')
        return 2;

    if(x == '^')
        return 3;

    return 0;
}

int main() {

    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++) {

        char symbol = infix[i];

        /* If operand, add to postfix */
        if(isalnum(symbol)) {
            postfix[j++] = symbol;
        }

        /* If opening bracket, push to stack */
        else if(symbol == '(') {
            push(symbol);
        }

        /* If closing bracket, pop until '(' */
        else if(symbol == ')') {

            while(top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            pop(); // Remove '('
        }

        /* If operator */
        else {

            while(top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }

            push(symbol);
        }
    }

    /* Pop remaining operators from stack */
    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}