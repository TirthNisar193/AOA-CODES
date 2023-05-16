#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100
// Define a function to print the colors assigned to each vertex
void printColors(int colors[], int n) {
    printf("Vertex colors:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}
// Define the graph coloring function
void graphColoring(int graph[][MAX_VERTICES], int n, int m) {
    // Create an array to store the color assigned to each vertex
    int colors[n];
    // Initialize all vertices as uncolored
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }
    // Color the first vertex with the first color
    colors[0] = 1;
    // Loop through the remaining vertices
    for (int i = 1; i < n; i++) {
        // Create a boolean array to store the available colors for the current vertex
        bool available[m+1];
        for (int j = 0; j <= m; j++) {
            available[j] = true;
        }
        // Check the colors assigned to the adjacent vertices
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                available[colors[j]] = false;
            }
        }
        // Assign the first available color
        for (int j = 1; j <= m; j++) {
            if (available[j]) {
                colors[i] = j;
                break;
            }
        }
    }
    // Print the colors assigned to each vertex
    printColors(colors, n);
}
int main() {
    // Create the graph
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    // Color the graph
    graphColoring(graph, n, m);
    return 0;
}
