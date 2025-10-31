// Write a program to implement Breadth first search Algorithm using adjacency matrix.

#include <stdio.h>
#define max 10

int adjMatrix[max][max];
int numVertices;
int visited[max];

int queue[max];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == max - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    int item = queue[front];
    front++;
    return item;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
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

void BFS(int startVertex) {
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    initializeGraph(5);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    printf("BFS (from vertex 0): \n");
    BFS(0);
    printf("\n");

    return 0;
}