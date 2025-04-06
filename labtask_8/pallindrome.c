#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;


void push(char ch) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}


char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}


int Palindrome(char str[]) {
    int length = 0;


    while (str[length] != '\0') {
        length++;
    }

    
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }

    
    for (int i = 0; i < length; i++) {
        if (str[i] != pop()) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (Palindrome(str)) {
        printf("The string is a palindrome \n");
    } else {
        printf("The string is not a palindrome \n");
    }

    return 0;
}
