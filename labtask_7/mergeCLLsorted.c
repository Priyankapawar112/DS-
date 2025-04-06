#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

struct Node* insertSorted(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);

    if (tail == NULL)
        return newNode;

    struct Node* curr = tail->next;
    struct Node* prev = tail;

    do {
        if (data <= curr->data)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    newNode->next = curr;
    prev->next = newNode;

    if (prev == tail && data >= tail->data)
        tail = newNode;

    return tail;
}

void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

struct Node* mergeLists(struct Node* tail1, struct Node* tail2) {
    if (tail1 == NULL) return tail2;
    if (tail2 == NULL) return tail1;

    struct Node* mergedTail = NULL;
    struct Node* curr1 = tail1->next;
    struct Node* curr2 = tail2->next;
    struct Node* head1 = curr1;
    struct Node* head2 = curr2;

    do {
        mergedTail = insertSorted(mergedTail, curr1->data);
        curr1 = curr1->next;
    } while (curr1 != head1);

    do {
        mergedTail = insertSorted(mergedTail, curr2->data);
        curr2 = curr2->next;
    } while (curr2 != head2);

    return mergedTail;
}

struct Node* createList() {
    struct Node* tail = NULL;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        tail = insertSorted(tail, data);
    }

    return tail;
}

int main() {
    printf("Create first sorted circular linked list:\n");
    struct Node* tail1 = createList();

    printf("Create second sorted circular linked list:\n");
    struct Node* tail2 = createList();

    printf("First list: ");
    display(tail1);

    printf("Second list: ");
    display(tail2);

    struct Node* mergedTail = mergeLists(tail1, tail2);
    printf("Merged sorted circular linked list: ");
    display(mergedTail);

    return 0;
}
