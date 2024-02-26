#include <stdio.h>

#define MAX 10

int path[MAX];
int graph[MAX][MAX];
int vertices;

void displayHamiltonianCircuit() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", path[i] + 1); 
    }
    printf("%d\n", path[0] + 1); 
}

int isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return 0;  
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return 0;  
        }
    }

    return 1;
}

int hamiltonianUtil(int pos) {
    if (pos == vertices) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return 1;  // Hamiltonian circuit found
        } else {
            return 0;  // Hamiltonian circuit not found
        }
    }

    for (int v = 1; v < vertices; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(pos + 1) == 1) {
                return 1;
            }

            path[pos] = -1;  // Backtrack
        }
    }

    return 0;
}

void findHamiltonianCircuit() {
    for (int i = 0; i < vertices; i++) {
        path[i] = -1;
    }

    path[0] = 0;  

    if (hamiltonianUtil(1) == 0) {
        printf("Hamiltonian Circuit does not exist\n");
    } else {
        displayHamiltonianCircuit();
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (separate each element by space):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    findHamiltonianCircuit();

    return 0;
}
