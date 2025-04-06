#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addToEmpty(int data){
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp; 
}

struct node *insertAtEnd( struct node *tail, int data){
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q -> data = data;

    if ( tail == NULL){
        q -> next = q;
        return q;
    }
    
    struct node *temp = tail -> next;
    while (temp->next != tail -> next) {
        temp = temp->next;
    }
    
    q -> next =tail -> next;
    tail -> next = q;
    
    return tail;

}




struct node *createList( struct node *tail){
    int i, n, data;

    printf("enter number of nodes :");
    scanf("%d", &n);

    if(n==0)
    return tail;


    printf("enter the element 1 : ");
    scanf("%d",&data);
    tail = addToEmpty(data);

    for (i=1; i<n; i++){

    printf("enter the element %d : ", i+1);
    scanf("%d",&data);
    tail = insertAtEnd( tail , data);
        
    }

    return tail;
}

void display(struct node *head) {
    struct node *temp = head;
    
        do {
            printf("%d  ", temp->data);
            temp = temp->next;
        } while (temp != head);  
    
}

struct node *deletionAtBegin( struct node *tail ){
    
    if ( tail == NULL ){
    printf(" empty \n");
    return NULL ;
    }

    struct node *temp = tail -> next;

    if ( tail -> next == tail){
        free(temp);
        return NULL;
        
    }
    

    tail -> next = temp -> next ;
    free(temp);
    return tail;
}

struct node *deletionAtEnd( struct node *tail ){

    
    if ( tail == NULL ){
    printf(" empty \n");
    return NULL ;
    }
   
    struct node *curr;
    curr = tail -> next;


    if ( tail == tail -> next){
        free(tail);
        return NULL;
        
    }

    
    
    struct node *prev = NULL;
    
        while(curr -> next != tail -> next) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = tail -> next;
        free(curr);
        return prev;
    }
    




int main() {
    
    
    struct node *tail = NULL;

    tail = createList(tail);
    printf(" circular LL : ");
    display(tail);
    
  printf("\n");

    tail = deletionAtBegin( tail );
    printf(" circular LL after deletion at starting : ");
    display(tail);
    
   printf("\n");
    tail = deletionAtEnd( tail );
    printf(" circular LL after deletion at end: ");
    display(tail);
    

    return 0;
}