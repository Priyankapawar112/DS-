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


void Frequency(struct node* head) {
    struct node* p = head;
    struct node* q;
    int visited = -1;

    while (p != NULL) {
        int count = 1;
        q = p->next;

        while (q != NULL) {
            if (p->data == q->data) {
                count++;
                q->data = visited;  
            }
            q = q->next;
        }

        if (p->data != visited) {
            printf("Element %d occurs %d times\n", p->data, count);
        }

        p = p->next;
    }
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
    third->data = 10;
    third->next = fourth;
    fourth->data = 20;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = sixth;
    sixth->data = 7;
    sixth->next = seventh;
    seventh->data = 5;
    seventh->next = NULL;

    printf("The original Linked List: ");
    display(head);

    printf("\nFrequency of each element:\n");
    Frequency(head);

    
    return 0;
}
