#include<stdio.h>
struct Item {
    int weight;
    int value;
};
int knapsackGreedy(int W, struct Item items[], int n) {
    int totalValue = 0;
    double valuePerWeight[n];
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)items[i].value / items[i].weight;
    }
    while (W > 0) {
        double maxRatio = 0;
        int maxIndex = -1;
        for (int i = 0; i < n; i++) {
            if (valuePerWeight[i] > maxRatio && items[i].weight <= W) {
                maxRatio = valuePerWeight[i];
                maxIndex = i;
            }
        }
        if (maxIndex == -1) break;
        int amount = (W >= items[maxIndex].weight) ? items[maxIndex].weight : W;
        totalValue += amount * items[maxIndex].value / items[maxIndex].weight;
        W -= amount;
        valuePerWeight[maxIndex] = 0;
    }
    return totalValue;
}
int main() {
    int n, W; 
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);
    int maxValue = knapsackGreedy(W, items, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);
    return 0;
}
