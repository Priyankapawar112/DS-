// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *prev;
//     struct node *next;
// };

// struct node *head = NULL;

// void display(struct node *head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct node *temp = head;
//     do {
//         printf("%d  ", temp->data);
//         temp = temp->next;
//     } while (temp != head);
//     printf("\n");
// }

// struct node* create_dll() {
//     struct node *temp, *nnode;
//     int choice = 1;

//     head = NULL;
//     while (choice) {
//         nnode = (struct node *)malloc(sizeof(struct node));

//         printf("Enter data: ");
//         scanf("%d", &nnode->data);

//         nnode->prev = NULL;
//         nnode->next = NULL;

//         if (head == NULL) {
//             head = temp = nnode;
//         } else {
//             temp->next = nnode;
//             nnode->prev = temp;
//             temp = nnode;
//         }

//         printf("Do you want to continue? (1 for yes, 0 for no): ");
//         scanf("%d", &choice);
//     }


//     if (head != NULL) {
//         temp->next = head;
//         head->prev = temp;
//     }

//     return head;
// }

// struct node *insertion_starting(struct node *head) {
//     struct node *outnode =  (struct node *)malloc(sizeof(struct node));

//     printf("Enter the data of starting node: ");
//     scanf("%d", &outnode->data);
//     outnode->next = NULL;
//     outnode->prev = NULL;

//     if (head == NULL) {
//         outnode->next = outnode;
//         outnode->prev = outnode;
//         return outnode;
//     }
     
    

//     struct node *last = head->prev;

    
//     outnode->next = head;
//     outnode->prev = last;
//     last->next = outnode;
//     head->prev = outnode;

    
//     head = outnode;
//     return head;  
// }


// struct node *insertion_end(struct node *head) {
//     struct node *outnode =  (struct node *)malloc(sizeof(struct node));
//     struct node *temp;
//     temp = head;
//     printf("Enter the data of starting node: ");
//     scanf("%d", &outnode->data);
//     outnode->next = NULL;
//     outnode->prev = NULL;

//     if (head == NULL) {
//         outnode->next = outnode;
//         outnode->prev = outnode;
//         return outnode;
//     }
     
//     struct node *temp = head;
//     while( temp != NULL){
    
//         temp = temp -> next;
        
//    }
   
//     outnode -> temp;
//     temp -> prev = outnode;

//     return head;
// }



// int main() {
//     head = create_dll();
//     printf("The doubly linked list is: ");
//     display(head);
//     printf("\n");

    
//     head = insertion_starting(head);
//     printf("Insertion at beginning:\n");
//     display(head);

//     return 0;
// }




#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

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

struct node *addEmptyNode(struct node *head, int data){

    struct node  *temp=  (struct node *)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
}

struct node *addStart(struct node *head, int data){

    struct node  *temp=  (struct node *)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    temp -> next = head;
    head -> prev = temp;
    head = temp;

    return head;
}


struct node *addEnd(struct node *head, int data){
    struct node  *p;
    struct node  *temp=  (struct node *)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    p = head;
    while( p -> next != NULL)
        p = p -> next;
    p -> next = temp;
    temp -> prev = p;
    
    return head;
}


struct node *addAfterPosition(struct node *head, int position, int data){
    struct node  *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;

    newp = addEmptyNode(newp, data);
    
    while(position != 1){
        temp = temp -> next;
        position -- ;
    }
   if(temp -> next == NULL){
    temp -> next = newp;
    newp -> prev =temp;
   }
   else{
    temp2 = temp -> next;
    temp -> next = newp;
    temp2 -> prev = newp;
    newp -> next = temp2;
    newp -> prev = temp;
   }
    
    return head;
}




int main (){
    struct node *head;
    head = NULL;
    int position = 3;
    head = addEmptyNode(head, 5);
    head = addStart(head, 9);
    head = addStart(head, 10);
    head = addStart(head, 7);
    head = addEnd(head, 90);
    head = addAfterPosition(head, position, 34);
    display(head);


    return 0;
}