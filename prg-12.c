// 12. Write a program to evaluate a postfix expression 5 3+8 2 - *.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100  
 
int stack[MAX];
int top = -1;

 
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}


int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

 
int evaluatePostfix(char* expression) {
int i;
    for ( i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

       
        if (token == ' ') continue;

        
        if (isdigit(token)) {
            push(token - '0');  
        } else {  
            int operand2 = pop();  
            int operand1 = pop();

            switch (token) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", token);
                    exit(1);
            }
        }
    }
    return pop(); 
}

int main() {
    char postfix[] = "5 3 + 8 2 - *";  
    int result = evaluatePostfix(postfix);  

    printf("The result of the postfix expression '%s' is: %d\n", postfix, result);
    
    return 0;
}