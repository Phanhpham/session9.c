//
//  bai3.c
//  codeC
//
//  Created by USED on 16/12/24.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int matrix[MAX][MAX];
int visited[MAX];
int parent[MAX];
int numVertices;
int isDirected;


void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
        visited[i] = 0;
        parent[i] = -1;
    }
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    matrix[u][v] = 1;
    if (!isDirected) {
        matrix[v][u] = 1;
    }
}

// DFS function to detect cycles
int detectCycleDFS(int vertex) {
    visited[vertex] = 1;
    for (int adj = 0; adj < numVertices; adj++) {
        if (matrix[vertex][adj]) {
            if (!visited[adj]) {
                parent[adj] = vertex;
                if (detectCycleDFS(adj)) {
                    return 1;
                }
            } else {
               
                if (isDirected && visited[adj] == 1) {
                    return 1;
                }

               
                if (!isDirected && adj != parent[vertex]) {
                    return 1;
                }
            }
        }
    }
    visited[vertex] = 2;
    return 0;
}

// Function to check for cycles in the graph
int hasCycle() {
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (detectCycleDFS(i)) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to print the adjacency matrix
void printMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int edges, u, v;

    // Input number of vertices and whether the graph is directed
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    // Initialize the graph
    initializeGraph(numVertices);

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Print adjacency matrix
    printMatrix();

    // Check for cycles
    if (hasCycle()) {
        printf("\nThe graph contains a cycle.\n");
    } else {
        printf("\nThe graph does not contain any cycles.\n");
    }
    return 0;
}

