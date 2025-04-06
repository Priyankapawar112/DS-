#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* top = NULL;


void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = top;

    if (top != NULL)
        top->prev = newNode;

    top = newNode;
    
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("%d popped from stack.\n", temp->data);

    top = top->next;
    if (top != NULL)
        top->prev = NULL;

    free(temp);
}


void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d     ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    push(5);
    push(20);
    push(39);
    display();

    pop();
    display();


    return 0;
}
