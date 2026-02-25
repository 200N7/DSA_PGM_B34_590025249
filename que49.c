/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/

#include <stdio.h>
#include <stdlib.h>

// Define structure of a node
struct Node {
    int data;              // Data stored in node
    struct Node* next;     // Pointer to next node
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            // First node becomes head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Attach new node at the end
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;   // Return head of created list
}

// Function to count occurrences of key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    // Traverse the list
    while(temp != NULL) {
        if(temp->data == key) {
            count++;    // Increment counter if match found
        }
        temp = temp->next;  // Move to next node
    }

    return count;
}

int main() {

    int n;
    scanf("%d", &n);

    // Create linked list
    struct Node* head = createList(n);

    int key;
    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Print result
    printf("%d", result);

    return 0;
}