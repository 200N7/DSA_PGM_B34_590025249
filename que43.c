/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;              // To store data
    struct Node* next;     // Pointer to next node
};

int main() {

    int n;
    scanf("%d", &n);   // Read number of elements

    struct Node *head = NULL;   // Points to first node
    struct Node *tail = NULL;   // Points to last node
    struct Node *newNode = NULL;

    // Loop to create n nodes
    for(int i = 0; i < n; i++) {

        int value;
        scanf("%d", &value);  // Read element

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Assign data and initialize next pointer
        newNode->data = value;
        newNode->next = NULL;

        // If list is empty, new node becomes head and tail
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            // Attach new node at the end
            tail->next = newNode;

            // Move tail to the new last node
            tail = newNode;
        }
    }

    // Traverse the linked list and print elements
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;   // Move to next node
    }

    return 0;
}