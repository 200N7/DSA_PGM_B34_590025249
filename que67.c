/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Structure for stack node */
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Push function */
void push(int value) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

/* Pop function */
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }

    struct node *temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

/* Main function */
int main() {

    int a, b, result;
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        /* If digit, push to stack */
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        /* If operator */
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            b = pop();   // second operand
            a = pop();   // first operand

            switch (exp[i]) {

                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }

        i++;
    }

    /* Final result */
    printf("%d", pop());

    return 0;
}