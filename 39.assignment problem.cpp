#include <stdio.h>
#include <limits.h> 

#define N 4

int costMatrix[N][N];
int bestAssignment[N];  
int bestCost = INT_MAX;

void branchAndBoundAssignment(int currentAssignment[N], int currentCost, int worker) {
    if (worker == N) {
        if (currentCost < bestCost) {
            bestCost = currentCost;
            for (int i = 0; i < N; i++) {
                bestAssignment[i] = currentAssignment[i];
            }
        }
    } else {
        for (int job = 0; job < N; job++) {
            if (currentAssignment[job] == -1) {
                
                currentAssignment[job] = worker;

                int newCost = currentCost + costMatrix[worker][job];

                if (newCost < bestCost) {
                    branchAndBoundAssignment(currentAssignment, newCost, worker + 1);
                }

                currentAssignment[job] = -1;
            }
        }
    }
}

int main() {
    int currentAssignment[N];

    printf("Enter the cost matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        currentAssignment[i] = -1;
    }

    branchAndBoundAssignment(currentAssignment, 0, 0);

    printf("Best Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Job %d\n", i + 1, bestAssignment[i] + 1);
    }
    printf("Total Cost: %d\n", bestCost);

    return 0;
}

