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
void insertBeg(struct Node **head, int info) 
{
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
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
struct Node* search(struct Node *head, int data)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->info == data) 
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void insertAfter(struct Node **head, int data, int info)
{
    struct Node *temp = search(*head, data);
    if (temp == NULL) 
    {
        printf("%d not found\n", data);
        return;
    }
    struct Node *newNode = getNode(info);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove from beginning
void removeBeg(struct Node **head)
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Remove last node
void removeLast(struct Node **head)
{
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) 
    { 
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL) 
    { 
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Remove node after a specific node
void removeAfter(struct Node **head, int data)
{
    struct Node *temp = search(*head, data);
    if (temp == NULL || temp->next == NULL) 
    {
        printf("Cannot remove after %d\n", data);
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Main function
int main() 
{
    struct Node *head = NULL;
    int ch, info, data;

    do 
    {
        printf("\n ----------- LINKED LIST MENU ---------- \n");
        printf("1. Add Beginning\n");
        printf("2. Add Last\n");
        printf("3. Add After\n");
        printf("4. Remove Beginning\n");
        printf("5. Remove Last\n");
        printf("6. Remove After\n");
        printf("7. Search\n");
        printf("8. Traversal\n");
        printf("9. Exit\n");
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
                printf("Enter node value after which to insert: ");
                scanf("%d", &data);
                printf("Enter new info: ");
                scanf("%d", &info);
                insertAfter(&head, data, info);
                break;

            case 4:
                removeBeg(&head);
                break;

            case 5:
                removeLast(&head);
                break;

            case 6:
                printf("Enter node value after which to remove: ");
                scanf("%d", &data);
                removeAfter(&head, data);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(head, data) != NULL)
                    printf("%d found in list\n", data);
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
