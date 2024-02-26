#include <stdio.h>
void generateFactors(int n, int divisor) {
    if (divisor > n) {
        return;
    }
    if (n % divisor == 0) {
        printf("%d ", divisor);
    }
    generateFactors(n, divisor + 1);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    generateFactors(n, 1);
    return 0;
}
