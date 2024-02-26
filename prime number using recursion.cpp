#include <stdio.h>

int isPrime(int n) {
  if (n <= 1) {
    return 0;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

void printPrimeSeries(int n) {
  if (n <= 1) {
    return;
  }

  printPrimeSeries(n - 1);

  if (isPrime(n)) {
    printf("%d ", n);
  }
}

int main() {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  printPrimeSeries(n);

  return 0;
}
