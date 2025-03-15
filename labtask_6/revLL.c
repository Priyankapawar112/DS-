#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


void display(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


struct node  *reverse(struct node* head) {
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *temp;

    while( curr != NULL){
    
         temp = curr -> next;
         curr -> next = prev;
         prev = curr;
         curr = temp;
    }
    return prev;
    
}



int main() {
    struct node *head, *second, *third, *fourth, *fifth, *sixth, *seventh;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = sixth;
    sixth->data = 60;
    sixth->next = seventh;
    seventh->data = 70;
    seventh->next = NULL;

    printf("The original Linked List: ");
    display(head);
    
    head = reverse(head);

    printf("The reversed Linked List: ");
    display(head);

    
    return 0;
}
