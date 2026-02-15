#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], n, i, pos, val, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (n == MAX) {
                    printf("Array full, cannot insert!\n");
                    break;
                }
                printf("Enter value and position (0-based): ");
                scanf("%d %d", &val, &pos);

                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = n; i > pos; i--)
                        arr[i] = arr[i - 1];

                    arr[pos] = val;
                    n++;

                    printf("After insertion: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 2: 
                printf("Enter delete position (0-based): ");
                scanf("%d", &pos);

                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos; i < n - 1; i++)
                        arr[i] = arr[i + 1];

                    n--;

                    printf("After deletion: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 3: 
                printf("Traversal: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 4: 
             printf("\nThis code is executed by Riya with Roll No-2400320100920\n");
            break;
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}




