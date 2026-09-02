#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pi = partition(arr, low, high);

    if (k == pi)
        return arr[pi];

    else if (k < pi)
        return quickSelect(arr, low, pi - 1, k);

    else
        return quickSelect(arr, pi + 1, high, k);
}

int main()
{
    int n, i;
    int a, b;
    float median;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n % 2 != 0)
    {
        median = quickSelect(arr, 0, n - 1, n / 2);
    }
    else
    {
        a = quickSelect(arr, 0, n - 1, (n / 2) - 1);
        b = quickSelect(arr, 0, n - 1, n / 2);

        median = (a + b) / 2.0;
    }

    printf("Median = %.2f\n", median);

    return 0;
}