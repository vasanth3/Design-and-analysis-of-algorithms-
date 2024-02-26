#include <stdio.h>
void printPascalTriangle(int numRows) {
    int coefficient = 1;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coefficient = 1;
            else
                coefficient = coefficient * (i - j + 1) / j;
            printf("%d ", coefficient);
        }
        printf("\n");
    }
}
int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);
    printPascalTriangle(numRows);
    return 0;
}
