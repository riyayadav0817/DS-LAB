#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, pow;
    struct Node *next;
};

struct Node* createNode(int c, int p) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}

void addLast(struct Node **head, int c, int p) {
    struct Node *newNode = createNode(c, p);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->coeff >= 0 && temp != head)
            printf("+");

        printf("%dx^%d", temp->coeff, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addPoly(struct Node *poly1, struct Node *poly2) {
    struct Node *poly3 = NULL;

    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            addLast(&poly3, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } 
        else if (poly2->pow > poly1->pow) {
            addLast(&poly3, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } 
        else {
            addLast(&poly3, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        addLast(&poly3, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2) {
        
        addLast(&poly3, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return poly3;
}

struct Node* subPoly(struct Node *poly1, struct Node *poly2) {
    struct Node *poly3 = NULL;

    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            addLast(&poly3, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly2->pow > poly1->pow) {
            addLast(&poly3, -poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {
            addLast(&poly3, poly1->coeff - poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        addLast(&poly3, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2) {
        addLast(&poly3, -poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return poly3;
}

struct Node* multiplyPoly(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    for (struct Node *p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (struct Node *p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int pow = p1->pow + p2->pow;

            struct Node *temp = result;
            struct Node *prev = NULL;

            while (temp && temp->pow > pow) {
                prev = temp;
                temp = temp->next;
            }

            if (temp && temp->pow == pow) {
                temp->coeff += coeff;
            } 
            else {
                struct Node *newNode = createNode(coeff, pow);
                newNode->next = temp;

                if (prev == NULL)
                    result = newNode;
                else
                    prev->next = newNode;
            }
        }
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    addLast(&poly1, 3, 3);
    addLast(&poly1, 4, 2);
    addLast(&poly1, -5, 1);

    addLast(&poly2, 5, 3);
    addLast(&poly2, -2, 1);
    addLast(&poly2, 6, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node *sum = addPoly(poly1, poly2);
    struct Node *difference = subPoly(poly1, poly2);
    struct Node *product = multiplyPoly(poly1, poly2);

    printf("\nSum: ");
    display(sum);

    printf("Difference: ");
    display(difference);

    printf("Product: ");
    display(product);

    printf("\nThis code is executed by RIYA with Roll No. 2400320100920\n");

    return 0;
}
