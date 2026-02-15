#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0'; 
    return stack[top--];
}

int isMatching(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

int checkBalanced(const char *exp) {
    top = -1; 
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char open = pop();
            if (open == '\0' || !isMatching(open, c)) {
                return 0; 
            }
        }
        
    }
    return (top == -1);
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%c\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    char exp[100];

    while (1) {
        printf("\n--- Parentheses Balance Menu ---\n");
        printf("1. Check Balanced Expression\n");
        printf("2. Display Internal Stack (for debugging)\n");
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
                printf("Enter expression: ");
                if (scanf("%s", exp) != 1) {
                    printf("Input error. Returning to menu.\n");
                    break;
                }
                if (checkBalanced(exp))
                    printf("Balanced\n");
                else
                    printf("Not Balanced\n");
                break;

            case 2:
                displayStack();
                break;

            case 3:
                top = -1;
                printf("Stack cleared successfully.\n");
                break;

            case 4:
                printf("\nThis code is executed by Riya with Roll No. 2400320100920\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
