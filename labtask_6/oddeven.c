#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third, *fourth, *fifth, *sixth, *seventh;
    struct node *temp, *p, *odd_head, *even_head, *odd_tail, *even_tail;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 5;
    second->next = third;
    third->data = 20;
    third->next = fourth;
    fourth->data = 21;
    fourth->next = fifth;
    fifth->data = 12;
    fifth->next = sixth;
    sixth->data = 14;
    sixth->next = seventh;
    seventh->data = 7;
    seventh->next = NULL;

    printf("The linked list is:\n");
    display(head);

    
    temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    printf("\nThe size of the linked list is: %d\n", count);

    odd_head = NULL;
    even_head = NULL;
    odd_tail = NULL;
    even_tail = NULL;

    p = head;

    
    while (p != NULL) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = p->data;
        new_node->next = NULL;

        if (p->data % 2 == 0) { 
            if (even_head == NULL) {
                even_head = new_node; 
                even_tail = new_node; 
            } else {
                even_tail->next = new_node; 
                even_tail = new_node; 
            }
        } else { 
            if (odd_head == NULL) {
                odd_head = new_node; 
                odd_tail = new_node; 
            } else {
                odd_tail->next = new_node; 
                odd_tail = new_node; 
            }
        }

        p = p->next;
    }

    // Display the even and odd linked lists
    printf("\nThe even numbers are:\n");
    display(even_head);

    printf("\nThe odd numbers are:\n");
    display(odd_head);

    return 0;
}