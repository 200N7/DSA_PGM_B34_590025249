/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>

// Definition of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to find intersection based on VALUE
int findIntersection(struct Node* head1, struct Node* head2) {

    struct Node* temp1 = head1;

    // Traverse first list
    while (temp1 != NULL) {

        struct Node* temp2 = head2;

        // Compare with every node of second list
        while (temp2 != NULL) {

            if (temp1->data == temp2->data) {
                return temp1->data;   // First common value found
            }

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return -1;   // No intersection found
}

int main() {
    int n, m, value;

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}