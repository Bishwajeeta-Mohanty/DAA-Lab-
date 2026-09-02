#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;


    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
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

    
    heapSort(arr, n);

    printf("\n\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}