/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to next node
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            // First node becomes head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Attach at the end
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;   // Return head of created list
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {

    // Create a dummy node to simplify merging
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Compare nodes from both lists
    while(head1 != NULL && head2 != NULL) {

        if(head1->data <= head2->data) {
            tail->next = head1;      // Attach smaller node
            head1 = head1->next;     // Move in first list
        } else {
            tail->next = head2;      // Attach smaller node
            head2 = head2->next;     // Move in second list
        }

        tail = tail->next;   // Move tail forward
    }

    // If elements remain in list1
    if(head1 != NULL)
        tail->next = head1;

    // If elements remain in list2
    if(head2 != NULL)
        tail->next = head2;

    return dummy.next;   // Head of merged list
}

// Function to print linked list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {

    int n, m;

    // Read first list
    scanf("%d", &n);
    struct Node* head1 = createList(n);

    // Read second list
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    // Merge lists
    struct Node* mergedHead = mergeLists(head1, head2);

    // Print merged list
    printList(mergedHead);

    return 0;
}