#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* stack[50];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildExpressionTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        
        if (isalnum(postfix[i])) {
            push(createNode(postfix[i]));
        }
        
        else {
            struct Node* newNode = createNode(postfix[i]);
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
    }
    return pop(); 
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char postfix[50];

    do {
        printf("\n--- Expression Tree Menu ---\n");
        printf("1. Enter Postfix Expression\n");
        printf("2. Display Inorder (Infix)\n");
        printf("3. Display Preorder (Prefix)\n");
        printf("4. Display Postorder (Postfix)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                root = buildExpressionTree(postfix);
                printf("Expression Tree Created Successfully!\n");
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("\n This program is executed by RIYA with Roll No. 2400320100920)\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
