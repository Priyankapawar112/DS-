#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;


void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf(" Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}


void display() {
    struct Node* temp = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
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
