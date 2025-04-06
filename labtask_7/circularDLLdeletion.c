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
    newNode->prev = newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;

    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* tail = head->prev;
    struct Node* temp = head;

    head = head->next;
    head->prev = tail;
    tail->next = head;

    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* tail = head->prev;
    struct Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;

    free(tail);
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL)
        return NULL;

    if (pos <= 1)
        return deleteAtBeginning(head);

    struct Node* temp = head;
    int i;

    for (i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (temp == head)
        return head;

    struct Node* prevNode = temp->prev;
    struct Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    if (temp == head)
        head = nextNode;

    free(temp);
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        
        printf("1. Insert at End\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
        } else if (choice == 2) {
            head = deleteAtBeginning(head);
        } else if (choice == 3) {
            head = deleteAtEnd(head);
        } else if (choice == 4) {
            printf("Enter position: ");
            scanf("%d", &pos);
            head = deleteAtPosition(head, pos);
        } else if (choice == 5) {
            display(head);
        } else if (choice == 6) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
