#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;


void push(int val) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}


int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}


int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        
        if (ch == ' ' || ch == '(' || ch == ')')
            continue;

        
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        } else {
            
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push(power(a, b)); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    return pop(); 
}

int main() {
    char expression[SIZE];

    printf("Enter postfix expression : ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result = %d\n", result);

    return 0;
}
