#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void createGraph(int vertices, int edges) {
    int i;

    for (i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("\nEnter edges (u v):\n");
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

void BFS(int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adjList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    createGraph(vertices, edges);

    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);

    BFS(start, vertices);

     printf("\nThis program is executed by RIYA wiht Roll No. 2400320100920)\n");

    return 0;
}
