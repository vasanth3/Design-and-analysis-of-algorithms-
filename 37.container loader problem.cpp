#include <stdio.h>
#include <stdbool.h>
#define MAX_ITEMS 100
#define MAX_CONTAINERS 100
struct Item {
    int id;
    int size;
    bool packed;
};
struct Container {
    int id;
    int capacity;
    int filled;
};
void packItems(struct Item items[], int numItems, struct Container containers[], int numContainers) {
    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < numContainers; j++) {
            if (!items[i].packed && items[i].size <= containers[j].capacity - containers[j].filled) {
                items[i].packed = true;
                containers[j].filled += items[i].size;
                printf("Item %d packed into container %d\n", items[i].id, containers[j].id);
                break;
            }
        }
    }
}
int main() {
    struct Item items[MAX_ITEMS];
    struct Container containers[MAX_CONTAINERS];
    int numItems, numContainers;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i].size);
        items[i].id = i + 1;
        items[i].packed = false;
    }
    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);
    printf("Enter the capacities of the containers:\n");
    for (int i = 0; i < numContainers; i++) {
        scanf("%d", &containers[i].capacity);
        containers[i].id = i + 1;
        containers[i].filled = 0;
    }
    printf("Packing items into containers...\n");
    packItems(items, numItems, containers, numContainers);
    return 0;
}
