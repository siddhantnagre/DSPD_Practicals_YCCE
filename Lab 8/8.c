#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

// Disjoint Set (Union-Find)
int parent[100];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);
    parent[uRoot] = vRoot;
}

// Comparator for sorting edges
int cmp(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, E, sizeof(struct Edge), cmp);

    int mstWeight = 0;
    printf("\nEdges in MST:\n");
    for (int i = 0, count = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            unionSet(u, v);
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            count++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
    return 0;
}
