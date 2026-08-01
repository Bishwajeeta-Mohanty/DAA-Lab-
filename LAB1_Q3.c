#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// --------------------------------------------------
// Bubble Sort Version 1
// Stops if array becomes sorted before n-1 passes
// --------------------------------------------------

long long bubbleSortEarly(int arr[], int n)
{
    long long comparisons = 0;
    int swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }

    return comparisons;
}

// --------------------------------------------------
// Bubble Sort Version 2
// Always completes n-1 passes
// --------------------------------------------------

long long bubbleSortNormal(int arr[], int n)
{
    long long comparisons = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return comparisons;
}

// --------------------------------------------------
// Generate random array
// --------------------------------------------------

void generateArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

// --------------------------------------------------
// Main
// --------------------------------------------------

int main()
{
    int n;

    srand(time(NULL));

    printf("BUBBLE SORT PERFORMANCE ANALYSIS\n");
    printf("----------------------------------\n");

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int *original = (int *)malloc(n * sizeof(int));
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));

    if (original == NULL || arr1 == NULL || arr2 == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generateArray(original, n);

    for (int i = 0; i < n; i++)
    {
        arr1[i] = original[i];
        arr2[i] = original[i];
    }

    long long comparisons1 = bubbleSortEarly(arr1, n);
    long long comparisons2 = bubbleSortNormal(arr2, n);

    printf("\nResults:\n");
    printf("Array size = %d\n", n);

    printf("\nVersion 1 - Early Termination\n");
    printf("Comparisons = %lld\n", comparisons1);

    printf("\nVersion 2 - Normal Bubble Sort\n");
    printf("Comparisons = %lld\n", comparisons2);

    // ------------------------------------------
    // Generate data for plotting
    // ------------------------------------------

    FILE *fp = fopen("bubble_sort_data.csv", "w");

    if (fp == NULL)
    {
        printf("Could not create CSV file.\n");
        free(original);
        free(arr1);
        free(arr2);
        return 1;
    }

    fprintf(fp, "n,early_termination,normal_bubble_sort\n");

    for (int size = 10; size <= n; size += 10)
    {
        generateArray(original, size);

        for (int i = 0; i < size; i++)
        {
            arr1[i] = original[i];
            arr2[i] = original[i];
        }

        long long c1 = bubbleSortEarly(arr1, size);
        long long c2 = bubbleSortNormal(arr2, size);

        fprintf(fp, "%d,%lld,%lld\n", size, c1, c2);
    }

    fclose(fp);

    printf("\nData saved to bubble_sort_data.csv\n");

    free(original);
    free(arr1);
    free(arr2);

    return 0;
}