#include <stdio.h>
#include <time.h>
#define N 100 
void multiplyMatrices(int mat1[N][N], int mat2[N][N], int res[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int mat1[N][N];
    int mat2[N][N];
    int res[N][N];
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat1[i][j] = rand() % 10; 
            mat2[i][j] = rand() % 10;
        }
    }
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    multiplyMatrices(mat1, mat2, res);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", cpu_time_used);
    return 0;
}

