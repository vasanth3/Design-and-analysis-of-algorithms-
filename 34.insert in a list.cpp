#include <stdio.h>
#define MAX_SIZE 100
void insertNumber(int list[], int *size, int number, int position) {
    if (*size >= MAX_SIZE || position < 0 || position > *size) {
        printf("Insertion failed. List is full or invalid position.\n");
        return;
    }
    for (int i = *size - 1; i >= position; i--) {
        list[i + 1] = list[i];
    }
    list[position] = number;
    (*size)++;
    printf("Number %d inserted at position %d.\n", number, position);
}
void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
int main() {
    int list[MAX_SIZE];
    int size = 0;
    int number, position;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &size);
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &list[i]);
    }
    displayList(list, size);
    printf("Enter the number to insert: ");
    scanf("%d", &number);
    printf("Enter the position to insert (0-%d): ", size);
    scanf("%d", &position);
    insertNumber(list, &size, number, position);
    displayList(list, size);
    return 0;
}
