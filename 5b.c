#include <stdio.h>
#define MAX 100

void display(int a[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

int main() {
    int a[MAX], n = 0, choice, key;

    while (1) {
        printf("\n--- Binary Search Menu ---\n");
        printf("1. Enter Array (sorted)\n");
        printf("2. Search Element (Binary Search)\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }

        switch (choice) {

            case 1:
                printf("Enter number of elements (1-%d): ", MAX);
                if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
                    printf("Invalid size.\n");
                    return 0;
                }

                printf("Enter %d sorted elements:\n", n);
                for (int i = 0; i < n; i++) {
                    if (scanf("%d", &a[i]) != 1) {
                        printf("Invalid input. Exiting.\n");
                        return 0;
                    }
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Array not entered yet!\n");
                    break;
                }

                printf("Enter element to search: ");
                if (scanf("%d", &key) != 1) {
                    printf("Invalid input. Exiting.\n");
                    return 0;
                }

                int pos;
                pos = binarySearch(a, n, key);

                if (pos != -1)
                    printf("Element found at index %d\n", pos);
                else
                    printf("Element not found.\n");
                break;

            case 3:
                display(a, n);
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
