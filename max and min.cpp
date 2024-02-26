#include <limits.h>
#include <stdio.h>
void findMinimumMaximum(int arr[], int N)
{
    int i;
    int minE = INT_MAX, maxE = INT_MIN;
    for (i = 0; i < N; i++)
    {
        if (arr[i] < minE)
        {
            minE = arr[i];
        }
        if (arr[i] > maxE)
        {
            maxE = arr[i];
        }
    }
    printf("The minimum element is %d", minE);
    printf("\n");
    printf("The maximum element is %d", maxE);
    return;
}

// Driver Code
int main()
{

    // Given array
    int arr[100], N, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    printf("Enter the elements of the array: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Function call
    findMinimumMaximum(arr, N);

    return 0;
}

