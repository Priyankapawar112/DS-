#include<stdio.h>
#include<stdlib.h>

    struct node {
        int data;
        struct node *next;

    };

    void LLtraversal(struct node *ptr){

        while (ptr!=NULL)
        {
        printf("element:%d\n",ptr->data);
        ptr = ptr->next;

        }

    }

    struct node *insertatbeg(struct node *head, int data){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->head;
        prt->data=data;
        return prt;
    }

    struct node *insertatindex(struct node *head, int data, int index){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *p = head;
        int i=0;

        while(i!=index-1){

            p = p->next;
            i++;
        }
        ptr -> data= data;
        ptr -> next= p->next;
        p -> next= ptr;

        return head;
    }

    struct node *insertatend(struct node *head, int data){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr-> = data;
        struct node *p = head;

        while(p->next != NULL){
            p=p->next;
            ptr->next=NULL;

            return head;
        }



    int main ()
    {
        struct node *head;
        struct node *second;
        struct node *third;
        struct node *ptr;

        head = (struct node *)malloc(sizeof(struct node ));
        second = (struct node *)malloc(sizeof(struct node ));
        third = (struct node *)malloc(sizeof(struct node ));

        head->data=10;
        head->next=second;

        second->data=70;
        second->next=third;

        third->data=60;
        third->next=NULL;
        
        //insertion at first//

       printf("linked list before insertion\n");
        LLtraversal(head);
        head = insertatbeg(head, 45);
        printf("linked list after insertion\n");
        LLtraversal(head);

        //insertion at particular position//
        head = inertatindex(head, 89, 1);
        printf("linked list after insertion\n");
        LLtraversal(head);

        //insertion at end//
        head = inertatend(head, 67);
        printf("linked list after insertion\n");
        LLtraversal(head);


        }    return 0;
}
        


    
