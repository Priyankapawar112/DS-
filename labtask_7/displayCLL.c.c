#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head) {
    if (head == NULL) return; 
    struct node *temp = head;
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);

} 

int main() {
    struct node *head, *second, *third, *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 2;
    head->next = second;
    second->data = 72;
    second->next = third;
    third->data = 24;
    third->next = fourth;
    fourth->data = 23;
    fourth->next = head;

    display(head);

    return 0;
}
