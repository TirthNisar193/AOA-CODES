#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100001
#define MAX_M 200001

struct Edge {
    int u, v, w;
};

struct Node {
    int key, parent;
    char mst;
};

struct List {
    int node, weight;
    struct List *next;
};

int n, m;
struct Edge edges[MAX_M];
struct List *adj[MAX_N];
struct Node nodes[MAX_N];

void addEdge(int u, int v, int w) {
    struct List *new_node = (struct List *) malloc(sizeof(struct List));
    new_node->node = v;
    new_node->weight = w;
    new_node->next = adj[u];
    adj[u] = new_node;
}

void calculatePrimsMST() {
    // Initialization
    for (int i = 1; i <= n; i++) {
        nodes[i].key = INT_MAX;
        nodes[i].mst = 0;
        nodes[i].parent = -1;
    }

    nodes[1].key = 0;

    // Main loop
    for (int i = 1; i <= n; i++) {
        // Find minimum key node
        int mini = INT_MAX;
        int u;
        for (int v = 1; v <= n; v++) {
            if (!nodes[v].mst && nodes[v].key < mini) {
                mini = nodes[v].key;
                u = v;
            }
        }

        // Mark u as visited
        nodes[u].mst = 1;

        // Update adjacent nodes
        struct List *p = adj[u];
        while (p != NULL) {
            int v = p->node;
            int w = p->weight;
            if (!nodes[v].mst && w < nodes[v].key) {
                nodes[v].parent = u;
                nodes[v].key = w;
            }
            p = p->next;
        }
    }
}

void printMST() {
    for (int i = 2; i <= n; i++) {
        int u = nodes[i].parent;
        int v = i;
        int w = nodes[i].key;
        printf("%d %d %d\n", u, v, w);
    }
}

int main() {
    // Input graph
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Enter the values of edge %d: ", i + 1);
        scanf("%d%d%d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    // Calculate MST
    calculatePrimsMST();

    // Print MST
    printMST();

    return 0;
}
