/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            // First node
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;  // Attach at end
            tail = newNode;
        }
    }

    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Traverse list to find key
    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL) {
                // Key is in head node
                head = temp->next;
            } else {
                // Key is in middle or end
                prev->next = temp->next;
            }
            free(temp);   // Free memory of deleted node
            break;        // Delete only first occurrence
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Function to print linked list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Create linked list
    struct Node* head = createList(n);

    int key;
    scanf("%d", &key);

    // Delete first occurrence of key
    head = deleteKey(head, key);

    // Print updated list
    printList(head);

    return 0;
}