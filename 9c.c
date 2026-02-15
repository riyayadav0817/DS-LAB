#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- BST MENU (Find Max & Min) ---\n");
        printf("1. Insert Node\n");
        printf("2. Find Minimum\n");
        printf("3. Find Maximum\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                value = findMin(root);
                if (value != -1)
                    printf("Minimum value = %d\n", value);
                break;

            case 3:
                value = findMax(root);
                if (value != -1)
                    printf("Maximum value = %d\n", value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("This code is executed by RIYA with roll no. 2400320100920");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
