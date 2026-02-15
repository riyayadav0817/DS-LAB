#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert_pq(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    int i = size - 1;
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = value;
    size++;
    printf("Inserted %d\n", value);
}

void delete_pq() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d\n", pq[0]);
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }
    size--;
}

void display_pq() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Priority Queue (highest -> lowest): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete (remove highest priority)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid value input. Exiting.\n");
                    return 0;
                }
                insert_pq(val);
                break;

            case 2:
                delete_pq();
                break;

            case 3:
                display_pq();
                break;

            case 4:
                printf("\nThis code is executed by Riya with Roll No-2400320100920\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}
