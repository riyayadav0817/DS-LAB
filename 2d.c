#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
    else printf("Stack overflow while pushing '%c'\n", c);
}

char pop() {
    if (top == -1) {
        printf("Stack underflow on pop\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--) putchar(stack[i]), putchar('\n');
}

void infixToPostfix(const char *infix, char *postfix) {
    int i, j = 0;
    top = -1; 
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') pop();
            else {  }
        } else {
            while (top != -1 && stack[top] != '(' &&
                  ( precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c) && c != '^') )) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        if (stack[top] == '(' || stack[top] == ')') { pop();  }
        else postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    int choice;
    char infix[100], postfix[200];

    while (1) {
        printf("\n--- Infix to Postfix Menu ---\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Display Internal Stack (debug)\n");
        printf("3. Clear Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                top = -1;
                printf("Enter infix expression (no spaces): ");
                if (scanf("%s", infix) != 1) {
                    printf("Input error. Returning to menu.\n");
                    break;
                }
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                break;

            case 2:
                displayStack();
                break;

            case 3:
                top = -1;
                printf("Stack cleared successfully.\n");
                break;

            case 4:
                printf("\nThis code is executed by Riya with Roll No-2400320100920\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
