#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i, a, b, result;

    for (i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');  
        } else {

            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return 0;
            }
            push(result);
        }
    }
    return pop(); 
}

int main() {
    int choice;
    char exp[100];

    while (1) {
        printf("\n--- Postfix Evaluation Menu ---\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Display Stack\n");
        printf("3. Clear Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                top = -1;
                printf("Enter postfix expression: ");
                scanf("%s", exp);

                printf("Result = %d\n", evaluatePostfix(exp));
                break;

            case 2:
                if (top == -1)
                    printf("Stack is empty.\n");
                else {
                    printf("Stack elements (top to bottom):\n");
                    for (int i = top; i >= 0; i--)
                        printf("%d\n", stack[i]);
                }
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
