/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>

// Define structure of Doubly Linked List node
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to next node
    struct Node* prev;     // Pointer to previous node
};

int main() {

    int n;
    scanf("%d", &n);   // Number of nodes

    struct Node *head = NULL;   // Points to first node
    struct Node *tail = NULL;   // Points to last node
    struct Node *newNode = NULL;

    // Insert n elements into doubly linked list
    for(int i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;   // Assign data
        newNode->next = NULL;    // Initially next is NULL
        newNode->prev = NULL;    // Initially prev is NULL

        if(head == NULL) {
            // First node becomes head and tail
            head = newNode;
            tail = newNode;
        }
        else {
            // Link new node with last node
            tail->next = newNode;    // Old tail points to new node
            newNode->prev = tail;    // New node points back to old tail

            tail = newNode;         // Update tail
        }
    }

    // Traverse forward using next pointer
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;   // Move forward
    }

    return 0;
}