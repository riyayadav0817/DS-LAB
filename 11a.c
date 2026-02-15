#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int adjMatrix[MAX][MAX];

void createGraph(int vertices, int edges) {
    int i, j;

    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;

    for (i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("\nEnter edges (u v):\n");
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;   

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

void displayMatrix(int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayList(int vertices) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = adjList[i];
        printf("%d -> ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    int choice;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    createGraph(vertices, edges);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Display Adjacency Matrix\n");
        printf("2. Display Adjacency List\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMatrix(vertices);
                break;

            case 2:
                displayList(vertices);
                break;

            case 3:
                printf("\nThis program is executed by RIYA wiht Roll No. 2400320100920)\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 3);

    return 0;
}
