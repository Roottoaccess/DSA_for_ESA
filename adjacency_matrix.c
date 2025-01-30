#include <stdio.h>

#define N 4  // Number of vertices

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[N][N] = {0};  // Initialize with 0

    // Adding edges for an undirected graph
    int edges[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Because it's undirected
    }

    printf("Adjacency Matrix:\n");
    printMatrix(adjMatrix);
    return 0;
}