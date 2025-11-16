// Write a program to implement Depth first search Algorithm using adjacency matrix.

#include <stdio.h>
#define MAX 10

int visited[MAX];

void DFS(int adj[4][4], int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < 4; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(adj, i);
        }
    }
}

int main() {
    int adj[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    int start = 0;  // Start DFS from vertex 0

    // Mark all vertices as unvisited
    for (int i = 0; i < 4; i++)
        visited[i] = 0;

    printf("DFS traversal starting from vertex %d: ", start);
    DFS(adj, start);
    printf("\n");

    return 0;
}
