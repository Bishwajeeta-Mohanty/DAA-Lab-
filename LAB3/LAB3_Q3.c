#include <stdio.h>

long long comparisons = 0;

typedef struct
{
    int max;
    int min;
} MaxMinResult;

MaxMinResult findMaxMin(int arr[], int low, int high)
{
    MaxMinResult result;
    MaxMinResult leftResult, rightResult;

    if (low == high)
    {
        result.max = arr[low];
        result.min = arr[low];

        return result;
    }

    if (high == low + 1)
    {
        comparisons++;

        if (arr[low] > arr[high])
        {
            result.max = arr[low];
            result.min = arr[high];
        }
        else
        {
            result.max = arr[high];
            result.min = arr[low];
        }

        return result;
    }

    int mid = (low + high) / 2;

    leftResult = findMaxMin(arr, low, mid);
    rightResult = findMaxMin(arr, mid + 1, high);

    comparisons++;

    if (leftResult.max > rightResult.max)
        result.max = leftResult.max;
    else
        result.max = rightResult.max;

    comparisons++;

    if (leftResult.min < rightResult.min)
        result.min = leftResult.min;
    else
        result.min = rightResult.min;

    return result;
}

int main()
{
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    comparisons = 0;

    MaxMinResult result = findMaxMin(arr, 0, n - 1);

    printf("\nMaximum element = %d\n", result.max);
    printf("Minimum element = %d\n", result.min);

    printf("Number of comparisons = %lld\n", comparisons);

    printf("Theoretical maximum comparisons = ");

    if (n % 2 == 0)
        printf("%d", (3 * n) / 2 - 2);
    else
        printf("%d", (3 * (n - 1)) / 2);

    printf("\n");

    return 0;
}