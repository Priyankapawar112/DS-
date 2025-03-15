#include<stdio.h>
struct node {
    int data;
    struct node *next;

};

void display(struct node *ptr){
    while(ptr!=0){
        printf("%d  ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *temp;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head -> data = 2;
    head -> next = second;
    second -> data = 72;
    second -> next = third;
    third -> data = 24;
    third -> next = fourth;
    fourth -> data = 23;
    fourth -> next = NULL;

    // traverse and  display linked list//

    printf("The linked list is :\n");
    display(head);

    temp = head;
    int count=0;

    while(temp!=0){
        temp = temp -> next;
        count++;
    }

    printf("\nThe size of the llinked list is : %d", count);
    


    return 0;
}