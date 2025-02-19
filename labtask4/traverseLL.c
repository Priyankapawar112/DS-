#include<stdio.h>
#include<stdlib.h>
int main(){

    struct node {
        int data;
        struct node *next;

    };
    //creating and displaying linked list

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

        second->data=10;
        second->next=third;

        third->data=10;
        third->next=NULL;

        head=ptr;

        while (ptr!=NULL){
            printf("element:%d\n",ptr->data);
            ptr = ptr->next;

        }


        }


    return 0;
}