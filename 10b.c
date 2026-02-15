#include <stdio.h>
#define MAX 100
int heap[MAX];
int size = 0;

void insertHeap(int value) {
    size++;
    heap[size] = value;
    int i = size;

    while (i > 1 && heap[i] > heap[i/2]) {
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i/2;
    }
}

void heapifyDown(int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapifyDown(largest);
    }
}

int deleteHeap() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int deletedValue = heap[1];

    heap[1] = heap[size];
    size--;

    heapifyDown(1);

    return deletedValue;
}

void displayHeap() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n--- MAX HEAP - DELETION MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Root Element\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertHeap(value);
                printf("Inserted!\n");
                break;

            case 2:
                value = deleteHeap();
                if (value != -1)
                    printf("Deleted root element: %d\n", value);
                break;

            case 3:
                displayHeap();
                break;

            case 4:
                printf("\nThis program is executed by RIYA wiht Roll No. 2400320100920)\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
