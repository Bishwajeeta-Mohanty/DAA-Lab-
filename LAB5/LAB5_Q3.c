#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    FILE *fp;
    int n, i;
    int arr[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000)
    {
        printf("Invalid number of elements.\n");
        return 0;
    }

    srand(time(NULL));

    /* Generate random elements and store in file */
    fp = fopen("numbers.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    printf("\nRandom elements generated:\n");

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        fprintf(fp, "%d ", arr[i]);
        printf("%d ", arr[i]);
    }

    fclose(fp);

    
    fp = fopen("numbers.txt", "r");

    if (fp == NULL)
    {
        printf("\nError opening file.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);


    quickSort(arr, 0, n - 1);

    printf("\n\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}