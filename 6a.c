#include <stdio.h>
#define MAX 100

int hashFunction(int key, int size) {
    return key % size;
}

void displayHashValues(int keys[], int n, int size) {
    if (n == 0) {
        printf("No keys entered yet!\n");
        return;
    }

    printf("Key\tHash Value\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", keys[i], hashFunction(keys[i], size));
    }
}

int main() {
    int choice;
    int size = 10;    
    int keys[MAX];
    int n = 0;

    while (1) {
        printf("\n--- Hash Function Menu ---\n");
        printf("1. Enter Hash Table Size\n");
        printf("2. Enter Keys\n");
        printf("3. Display Hash Values\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }

        switch (choice) {

            case 1:
                printf("Enter hash table size: ");
                if (scanf("%d", &size) != 1 || size <= 0) {
                    printf("Invalid size. Exiting.\n");
                    return 0;
                }
                printf("Hash table size updated to %d.\n", size);
                break;

            case 2:
                printf("Enter number of keys: ");
                if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
                    printf("Invalid number of keys. Exiting.\n");
                    return 0;
                }

                printf("Enter %d keys:\n", n);
                for (int i = 0; i < n; i++) {
                    if (scanf("%d", &keys[i]) != 1) {
                        printf("Invalid key input. Exiting.\n");
                        return 0;
                    }
                }
                break;

            case 3:
                displayHashValues(keys, n, size);
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
