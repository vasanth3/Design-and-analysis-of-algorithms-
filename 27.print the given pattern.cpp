#include <stdio.h>
void printPattern(int n) {
    if (n == 0) {
        return;
    }
    printPattern(n - 1); 
    for (int i = 1; i <= n; i++) {
        printf("%d", i); 
    }
    printf("\n"); 
}
int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printPattern(rows);
    return 0;
}
