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


int MatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


int areParenthesesBalanced(char expr[]) {
    int i = 0;
    while (expr[i] != '\0') {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char popped = pop();
            if (!MatchingPair(popped, ch)) {
                return 0;
            }
        }
        i++;
    }

    return top == -1;  
}

int main() {
    char expression[SIZE];

    printf("Enter an expression: ");
    scanf("%s", expression); 
    if (areParenthesesBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}
