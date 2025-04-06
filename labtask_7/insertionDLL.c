#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}


struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos <= 0) {
        printf(" Position should be 1 or greater.\n");
        return head;
    }

    if (pos == 1)
        return insertAtBeginning(head, data);

    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf(" Position too far! Inserting at the end.\n");
        return insertAtEnd(head, data);
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nDoubly Linked List: ");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    printf("🔗 Welcome to Doubly Linked List Manager!\n");

    while (1) {
        
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
        } else if (choice == 2) {
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
        } else if (choice == 3) {
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert at (starting from 1): ");
            scanf("%d", &pos);
            head = insertAtPosition(head, data, pos);
        } else if (choice == 4) {
            displayList(head);
        } else if (choice == 5) {
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid choice. Please enter 1 to 5.\n");
        }
    }

    return 0;
}
