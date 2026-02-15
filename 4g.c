#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBeg(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

struct Node* search(struct Node *head, int data) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void insertAfter(struct Node *head, int data, int newVal) {
    struct Node *temp = search(head, data);
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }

    struct Node *newNode = createNode(newVal);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteBeg(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

void deleteSpecific(struct Node **head, int data) {
    struct Node *temp = search(*head, data);

    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;  

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;  

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int ch, data, val;

    do {
        printf("\n---- DOUBLY LINKED LIST MENU ----\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert After\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Specific\n");
        printf("7. Search\n");
        printf("8. Traverse Forward\n");
        printf("9. Traverse Reverse\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
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
                insertEnd(&head, data);
                break;

            case 3:
                printf("Insert after value: ");
                scanf("%d", &data);
                printf("New value: ");
                scanf("%d", &val);
                insertAfter(head, data, val);
                break;

            case 4:
                deleteBeg(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteSpecific(&head, data);
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
                reverseTraverse(head);
                break;

            case 10:
                printf("\nThis code is executed by RIYA with Roll No. 2400320100920\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 10);

    return 0;
}
