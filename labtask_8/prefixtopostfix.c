#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;


int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}


int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


void push(char *str) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++top], str);
}


char* pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return "";
    }
    return stack[top--];
}


void prefixToPostfix(char prefix[]) {
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (ch == ' ' || ch == '(' || ch == ')') {
            continue;
        }

        if (isDigit(ch)) {
            char operand[2] = {ch, '\0'};
            push(operand);
        } else if (isOperator(ch)) {
            if (top < 1) {
                printf("Invalid prefix expression!\n");
                return;
            }

            char op1[MAX], op2[MAX], expr[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());

            sprintf(expr, "%s%s%c", op1, op2, ch);
            push(expr);
        }
    }

    if (top == 0) {
        printf("Postfix Expression: %s\n", stack[top]);
    } else {
        printf("Invalid expression.\n");
    }
}


int main() {
    char prefix[MAX];

    printf("Enter prefix expression : ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}
