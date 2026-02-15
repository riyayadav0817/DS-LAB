#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node* getNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    struct Node *temp = head->next; 
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != head->next);
    printf("\n");
}

void insertBeg(struct Node **head, int data) {
    struct Node *newNode = getNode(data);

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } 
    else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

void insertLast(struct Node **head, int data) {
    struct Node *newNode = getNode(data);

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } 
    else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode; 
    }
}

struct Node* search(struct Node *head, int data) {
    if (head == NULL) return NULL;

    struct Node *temp = head->next;
    do {
        if (temp->info == data)
            return temp;
        temp = temp->next;
    } while (temp != head->next);

    return NULL;
}

void insertAfter(struct Node **head, int data, int newVal) {
    struct Node *temp = search(*head, data);
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }

    struct Node *newNode = getNode(newVal);
    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == *head)
        *head = newNode; 
}

void removeBeg(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } 
    else {
        struct Node *first = (*head)->next;
        (*head)->next = first->next;
        free(first);
    }
}

void removeLast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = (*head)->next;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = (*head)->next;
    free(*head);
    *head = temp;
}

void removeAfter(struct Node **head, int data) {
    if (*head == NULL) return;

    struct Node *temp = search(*head, data);
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }

    struct Node *del = temp->next;

    if (del == *head)
        *head = temp;

    if (del == temp) { 
        *head = NULL;
    }

    temp->next = del->next;
    free(del);
}

int main() {
    struct Node *head = NULL;
    int ch, data, val;

    do {
        printf("\n---- CIRCULAR LINKED LIST MENU ----\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert Last\n");
        printf("3. Insert After\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete Last\n");
        printf("6. Delete After\n");
        printf("7. Search\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertBeg(&head, data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertLast(&head, data);
                break;

            case 3:
                printf("Enter node value after which to insert: ");
                scanf("%d", &data);
                printf("Enter new value: ");
                scanf("%d", &val);
                insertAfter(&head, data, val);
                break;

            case 4:
                removeBeg(&head);
                break;

            case 5:
                removeLast(&head);
                break;

            case 6:
                printf("Enter node value after which to delete: ");
                scanf("%d", &data);
                removeAfter(&head, data);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(head, data))
                    printf("%d found\n", data);
                else
                    printf("%d not found\n", data);
                break;

            case 8:
                traverse(head);
                break;

            case 9:
                printf("\nThis code is executed by RIYA with Roll No. 2400320100920\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 9);

    return 0;
}
