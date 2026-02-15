#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) 
{
    if (root == NULL)
        return createNode(data);

    int choice;
    printf("Insert %d to LEFT(1) or RIGHT(2) of %d ? ", data, root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

int countNodes(struct Node* root) 
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct Node* root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() 
{
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Count Nodes\n");
        printf("3. Display Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (root == NULL)
                    root = createNode(value);
                else
                    insertNode(root, value);
                break;

            case 2:
                printf("Total number of nodes = %d\n", countNodes(root));
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("\n This program is executed by RIYA with Roll No. 2400320100920)\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
