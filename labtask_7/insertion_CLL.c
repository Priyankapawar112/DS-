#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head) {
    struct node *temp = head;
    if (head != NULL) {
        do {
            printf("%d  ", temp->data);
            temp = temp->next;
        } while (temp != head);  
    }
}



struct node *insertAtBegin( struct node *head, int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p -> data = data;
    if ( head == NULL){
        p -> next = p;
        return p;
    }
    
    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    p->next = head;
    temp->next = p;
    return p;


}

struct node *insertAtEnd( struct node *head, int data){
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q -> data = data;
    if ( head == NULL){
        q -> next = q;
        return q;
    }
    
    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp -> next = q;
    q -> next = head; 
    return head;

}

int getLength(struct node *head) {
    if (head == NULL) return 0;
    struct node *temp = head;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

struct node *insertAtParticularPosition( struct node *head , int data, int position){
    int l = getLength(head);
    int i = 1;
    struct node *nnode, *temp;


    if ( position<0 || position>l ){
        printf("invalid position \n");
        return head;
    }
    else if ( position == 1){
        return insertAtBegin( head, data);}
        else if ( position == l + 1){
            return insertAtEnd( head, data);}
    else{
        nnode = (struct node *)malloc(sizeof(struct node));
        nnode -> data = data;

        struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
   
    temp = head -> next;
    while(i < position-1){
        temp = temp -> next;
        i++;
    }

    nnode -> next = temp -> next;
    temp -> next = nnode;

    }
    return head;

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
    printf("\n");
    
    
    head = insertAtBegin(head , 65);
    display(head);
    printf("\n");
    
    head = insertAtEnd(head , 75);
    display(head);
    printf("\n");

    head = insertAtParticularPosition(head , 795 , 2);
    display(head);


    return 0;
}