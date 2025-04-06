#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;


void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;

    }
}


void pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d is the popped element \n", stack[top]);
        top--;
    }
}


void display() {
    if (top < 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d   ", stack[i]);
        }
        printf("\n");
    }
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
