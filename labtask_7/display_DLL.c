#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct node* create_dll() {
    struct node *temp, *nnode;
    int choice = 1;

    head = NULL;
    while (choice) {
        nnode = (struct node *)malloc(sizeof(struct node));
        
        printf("Enter data: ");
        scanf("%d", &nnode->data);

        nnode->prev = NULL;
        nnode->next = NULL;

        if (head == NULL) {
            head = temp = nnode;
        } else {
            temp->next = nnode;
            nnode->prev = temp;
            temp = nnode;
        }

        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }


    

    return head;
}



int main() {
    head = create_dll();

    display(head);
    return 0;
}
