/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

#include <stdio.h>
#include <stdlib.h>

// Define structure for Circular Linked List node
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to next node
};

int main() {

    int n;
    scanf("%d", &n);   // Number of nodes

    struct Node *head = NULL;   // First node
    struct Node *tail = NULL;   // Last node
    struct Node *newNode = NULL;

    // Create circular linked list
    for(int i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            // First node
            head = newNode;
            tail = newNode;
        }
        else {
            // Attach at end
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Make the list circular
    if(tail != NULL) {
        tail->next = head;   // Last node points back to head
    }

    // Traverse circular linked list
    if(head != NULL) {
        struct Node* temp = head;

        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);   // Stop when we reach head again
    }

    return 0;
}