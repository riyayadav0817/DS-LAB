#include <stdio.h>

#define MAX 20

struct Edge 
{
    int u, v, wt;
};

int find(int parent[], int x) 
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSets(int parent[], int rank[], int x, int y) 
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else 
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void sortEdges(struct Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].wt > edges[j+1].wt) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

void kruskal(struct Edge edges[], int v, int e) {
    int parent[MAX], rank[MAX];

    for (int i = 0; i < v; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    sortEdges(edges, e);

    printf("\nEdges in MST:\n");
    int count = 0, totalCost = 0;

    for (int i = 0; i < e && count < v - 1; i++) {
        int u = edges[i].u;
        int v2 = edges[i].v;
        int wt = edges[i].wt;

        int setU = find(parent, u);
        int setV = find(parent, v2);

        if (setU != setV) {
            printf("%d -- %d  (cost = %d)\n", u, v2, wt);
            totalCost += wt;
            count++;

            unionSets(parent, rank, setU, setV);
        }
    }

    printf("\nTotal cost of MST = %d\n", totalCost);
}

int main() {
    int v, e;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edges[MAX];

    printf("\nEnter edges in format: u v weight\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].wt);
    }

    kruskal(edges, v, e);

    printf("\nThis program is executed by RIYA wiht Roll No. 2400320100920)\n");

    return 0;
}
