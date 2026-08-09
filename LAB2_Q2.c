#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long long normalComparisons = 0;
long long modifiedComparisons = 0;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        normalComparisons++;

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}


/* Normal Merge Sort */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void merge3(int arr[], int left, int mid1, int mid2, int right)
{
    int n = right - left + 1;

    int *temp = (int *)malloc(n * sizeof(int));

    int i = left;
    int j = mid1;
    int k = mid2;
    int index = 0;

    while (i < mid1 || j < mid2 || k <= right)
    {
        int minValue;
        int source;

        if (i < mid1)
        {
            minValue = arr[i];
            source = 1;
        }
        else if (j < mid2)
        {
            minValue = arr[j];
            source = 2;
        }
        else
        {
            minValue = arr[k];
            source = 3;
        }

        if (j < mid2)
        {
            modifiedComparisons++;

            if (arr[j] < minValue)
            {
                minValue = arr[j];
                source = 2;
            }
        }

        if (k <= right)
        {
            modifiedComparisons++;

            if (arr[k] < minValue)
            {
                minValue = arr[k];
                source = 3;
            }
        }

        temp[index++] = minValue;

        if (source == 1)
            i++;
        else if (source == 2)
            j++;
        else
            k++;
    }

    for (i = 0; i < n; i++)
        arr[left + i] = temp[i];

    free(temp);
}

void mergeSort3(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int n = right - left + 1;

    if (n < 3)
    {
        int mid = left;

        if (arr[left] > arr[right])
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }

        modifiedComparisons++;

        return;
    }

    int third = n / 3;

    int mid1 = left + third;
    int mid2 = left + 2 * third;

    mergeSort3(arr, left, mid1 - 1);
    mergeSort3(arr, mid1, mid2 - 1);
    mergeSort3(arr, mid2, right);

    merge3(arr, left, mid1, mid2, right);
}

void fillArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}


void copyArray(int source[], int destination[], int n)
{
    for (int i = 0; i < n; i++)
        destination[i] = source[i];
}


int main()
{
    
    int sizes[] = {
        27,
        81,
        243,
        729,
        2187,
        6561,
        19683
    };

    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    srand((unsigned int)time(NULL));

    printf("\n");
    printf("===============================================================\n");
    printf("       MERGE SORT VS MODIFIED 3-WAY MERGE SORT\n");
    printf("===============================================================\n");

    printf("%-10s %-25s %-30s\n",
           "n",
           "Normal Merge Sort",
           "Modified 3-Way Merge Sort");

    printf("---------------------------------------------------------------\n");

    for (int x = 0; x < numberOfSizes; x++)
    {
        int n = sizes[x];

        int *original = (int *)malloc(n * sizeof(int));
        int *array1 = (int *)malloc(n * sizeof(int));
        int *array2 = (int *)malloc(n * sizeof(int));

        if (original == NULL || array1 == NULL || array2 == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        fillArray(original, n);

        copyArray(original, array1, n);
        copyArray(original, array2, n);

        normalComparisons = 0;
        modifiedComparisons = 0;

        mergeSort(array1, 0, n - 1);

        mergeSort3(array2, 0, n - 1);

        printf("%-10d %-25lld %-30lld\n",
               n,
               normalComparisons,
               modifiedComparisons);

        free(original);
        free(array1);
        free(array2);
    }

    printf("---------------------------------------------------------------\n");

    printf("\nTHEORETICAL COMPLEXITY\n");
    printf("----------------------\n");

    printf("Normal Merge Sort   : T(n) = 2T(n/2) + O(n)\n");
    printf("                    : O(n log2 n)\n\n");

    printf("Modified Merge Sort : T(n) = 3T(n/3) + O(n)\n");
    printf("                    : O(n log3 n)\n\n");

    printf("Therefore both have:\n");
    printf("                    : O(n log n)\n");

    printf("\nProgram completed successfully!\n");

    return 0;
}
