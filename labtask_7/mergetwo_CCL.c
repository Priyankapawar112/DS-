#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *addToEmpty(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}


struct node *insertAtEnd(struct node *tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (tail == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    return newNode;  
}


struct node *createList() {
    struct node *tail = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) return NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        tail = insertAtEnd(tail, data);
    }

    return tail;
}

void display(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}


struct node *mergeCircularLists(struct node *tail1, struct node *tail2) {
    if (tail1 == NULL) return tail2;
    if (tail2 == NULL) return tail1;

    struct node *head1 = tail1->next;
    struct node *head2 = tail2->next;

  
    tail1->next = head2;
    tail2->next = head1;

    return tail2; 
}


int main() {
    struct node *tail1 = NULL;
    struct node *tail2 = NULL;
    struct node *mergedTail = NULL;

    printf("Creating Circular Linked List 1:\n");
    tail1 = createList();
    printf("List 1: ");
    display(tail1);

    printf("\nCreating Circular Linked List 2:\n");
    tail2 = createList();
    printf("List 2: ");
    display(tail2);

   
    mergedTail = mergeCircularLists(tail1, tail2);
    printf("\nMerged Circular Linked List: ");
    display(mergedTail);

    return 0;
}
