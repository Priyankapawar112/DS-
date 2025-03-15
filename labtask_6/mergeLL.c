// merging two given LL in sorted order

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* merge(struct node *p, struct node *q){
    
    struct node *sort=NULL, *tail=NULL;
    
    if (p == NULL) return q;
    if (q == NULL) return p;

    
        if ( p -> data  <=  q -> data){
            sort = p;
            p = p -> next;
        }
        else {
            sort = q;
            q = q -> next;
        }
        tail = sort;

    
    
    

    while (p!=NULL && q!=NULL){
        
            if ( p -> data  <=  q -> data){
                tail -> next = p;
                p = p -> next;
            }
            else {
                tail -> next = q;
                q = q -> next;
            }
            tail = tail -> next;
    } 
    if (p == NULL) tail -> next = q;
    if (q == NULL) tail -> next = p; 

    return sort;

}

void display(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
  
}

 



int main() {

    // 1st LL :

    struct node *head1;
    struct node *second;
    struct node *third, *fourth;
    struct node *p ;

    head1 = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
    head1->data = 10;
    head1->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = NULL;
    
     // 2nd LL

    struct node *head2;
    struct node *two;
    struct node *three, *four;
    struct node *q ;
    
    head2 = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));
    
    head2->data = 5;
    head2->next = two;
    two->data = 12;
    two->next = three;
    three->data = 14;
    three->next = four;
    four->data = 25;
    four->next = NULL;

    q = head2;

    struct node *sortedLL;
    sortedLL = merge(head1, head2);
     
    printf ("the sorted Linked List id : \n");
    display(sortedLL);

    return 0;
}