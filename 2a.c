#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int value) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}
void pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}
void display() {
    if (top == -1) 
    {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() 
{
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {  
            printf("Invalid input! Exiting to avoid infinite loop.\n");
            return 0;   
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input for value! Exiting.\n");
                    return 0;
                }
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nThis code is executed by Riya with Roll No-2400320100920\n");
                return 0;   

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
