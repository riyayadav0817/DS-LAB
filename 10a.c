#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insertHeap(int value) 
{
    if (size == MAX) 
    {
        printf("Heap is full!\n");
        return;
    }

    size++;
    int i = size;
    heap[i] = value;

    while (i > 1 && heap[i] > heap[i / 2]) 
    {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }

    printf("Inserted %d successfully.\n", value);
}

void displayHeap() 
{
    if (size == 0) 
    {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 1; i <= size; i++) 
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, value;

    do {
        printf("\n--- MAX HEAP - INSERTION MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Display Heap\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertHeap(value);
                break;

            case 2:
                displayHeap();
                break;

            case 3:
                printf("\nThis program is executed by RIYA wiht Roll No. 2400320100920)\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
