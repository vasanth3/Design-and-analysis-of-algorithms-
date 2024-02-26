#include <stdio.h>
#include <limits.h>
#define V 10 
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int parent[], int graph[V][V], int n) {
    printf("Vertex \t Optimal Cost\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t %d \n", parent[i], i, graph[i][parent[i]]);
}
void approximateTSP(int graph[V][V], int n) {
    int parent[V];
    int dist[V];
    int visited[V];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }

    printSolution(parent, graph, n);
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph (maximum %d): ", V);
    scanf("%d", &n);
    if (n > V || n <= 0) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", V);
        return 1;
    }
    int graph[V][V];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    approximateTSP(graph, n);
    return 0;
}
