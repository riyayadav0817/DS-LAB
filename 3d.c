#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {   // empty
        front = rear = 0;
    }
    else if (front == 0) {
        front = SIZE - 1;
    }
    else {
        front--;
    }
    deque[front] = x;
    printf("Inserted %d at FRONT\n", x);
}

void insertRear(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {   // empty
        front = rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = x;
    printf("Inserted %d at REAR\n", x);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from FRONT\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {               
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from REAR\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    printf("Deque: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at FRONT: ");
                if (scanf("%d", &val) != 1) { printf("Invalid value. Exiting.\n"); return 0; }
                insertFront(val);
                break;

            case 2:
                printf("Enter value to insert at REAR: ");
                if (scanf("%d", &val) != 1) { printf("Invalid value. Exiting.\n"); return 0; }
                insertRear(val);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("\nThis code is executed by Riya with Roll No-2400320100920\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}
