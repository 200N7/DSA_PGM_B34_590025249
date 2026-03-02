/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

// Define structure for polynomial node
struct Node {
    int coeff;            // Coefficient
    int exp;              // Exponent
    struct Node* next;    // Pointer to next term
};

int main() {

    int n;
    scanf("%d", &n);   // Number of terms

    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    // Create polynomial linked list
    for(int i = 0; i < n; i++) {

        int c, e;
        scanf("%d %d", &c, &e);

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->coeff = c;
        newNode->exp = e;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print polynomial in standard form
    struct Node* temp = head;

    while(temp != NULL) {

        // Printing rules
        if(temp->exp == 0) {
            printf("%d", temp->coeff);
        }
        else if(temp->exp == 1) {
            printf("%dx", temp->coeff);
        }
        else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Print + sign if not last term
        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}