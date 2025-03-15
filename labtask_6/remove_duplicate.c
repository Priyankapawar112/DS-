#include<stdio.h>
#include<stdlib.h>

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

struct node *remove_duplicate( struct node *head){
    struct node *p;
    struct node *q;
     p = head;
     q = p;

    while ( p != NULL && p -> next != NULL){
        if (p->data == p->next->data){
            q = p -> next ;
            p -> next = p -> next -> next ;
            free(q);}
            else{
                p = p -> next;
            }

        }

    return head ;

}




int main(){

    struct node *head;
    struct node *second;
    struct node *third, *fourth, *fifth, *sixth, *seventh;
    

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    seventh = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 20;
    third->next = fourth;
    fourth->data = 20;
    fourth->next = fifth;
    fifth->data = 31;
    fifth->next = sixth;
    sixth->data = 31;
    sixth->next = seventh;
    seventh->data = 40;
    seventh->next = NULL;

    printf("The original LL: ");
    display(head);

    head = remove_duplicate(head);

    printf("LL after removing duplicates: ");
    display(head);




    return 0;
}