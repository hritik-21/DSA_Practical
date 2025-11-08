// Write a program to implement Breadth first search Algorithm using adjacency matrix.

#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Enqueue function
void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Breadth First Search function
void BFS(int adj[4][4], int start) {
    int i, current;

    // Mark all vertices unvisited
    for (i = 0; i < 4; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal starting from vertex %d: ", start);

    while ((current = dequeue()) != -1) {
        printf("%d ", current);
        for (i = 0; i < 4; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int adj[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    int start = 0;  // Start BFS from vertex 0
    BFS(adj, start);

    return 0;
}
