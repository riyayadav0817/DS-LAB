#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

void initHashTable() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1; 
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int originalIndex = index;
    int i = 0;

    while(hashTable[index] != -1) {
        i++;
        index = (originalIndex + i) % SIZE;
        if(i == SIZE) {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

int search(int key) {
    int index = hash(key);
    int originalIndex = index;
    int i = 0;

    while(hashTable[index] != key) {
        if(hashTable[index] == -1) 
            return -1; 
        i++;
        index = (originalIndex + i) % SIZE;
        if(i == SIZE) 
            return -1; 
    }

    return index;
}

void display() {
    printf("Hash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    initHashTable();

    int n, key, choice;

    do {
        printf("\n--- Linear Probing Hash Table Menu ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = search(key);
                if(index != -1)
                    printf("Key %d found at index %d\n", key, index);
                else
                    printf("Key %d not found\n", key);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nThis code is executed by RIYA with Roll No. 2400320100920\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
