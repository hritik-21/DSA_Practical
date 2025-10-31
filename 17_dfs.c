// Write a program to implement Depth first search Algorithm using adjacency matrix.

#include <stdio.h>
#define max 10

int adjMatrix[max][max];
int numVertices;
int visited[max];

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; 
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

int main() {
    initializeGraph(5);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    printf("DFS (from vertex 0): \n");
    DFS(0);
    printf("\n");

    return 0;
}