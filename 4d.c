#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

struct Node *getNode(int info)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = info;
    temp->next = NULL;
    return temp;
}

void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeg(struct Node **head, int info){
    struct Node *newNode = getNode(info);
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node **head, int info)
{
    struct Node *newNode = getNode(info);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void reverse(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;     
        curr->next = prev;     
        prev = curr;           
        curr = next;           
    }

    *head = prev; 
}

int main()
{
    struct Node *head = NULL;
    int ch, info;

    do
    {
        printf("\n ----------- REVERSE LINKED LIST ----------- \n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Reverse Linked List\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter info: ");
                scanf("%d", &info);
                insertBeg(&head, info);
                break;

            case 2:
                printf("Enter info: ");
                scanf("%d", &info);
                insertLast(&head, info);
                break;

            case 3:
                reverse(&head);
                printf("Linked List Reversed Successfully!\n Now, traverse the linked list.\n");
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                printf("\nThis code is executed by RIYA with Roll No. 2400320100920\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 5);

    return 0;
}
