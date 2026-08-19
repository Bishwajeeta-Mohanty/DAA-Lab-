#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
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


int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int findKSum(int arr[], int n, int k, int T,
            int start, int depth, long long sum)
{
    
    if (depth == k - 1)
    {
        long long required = (long long)T - sum;

        int pos = binarySearch(arr, n, (int)required);

        if (pos != -1)
        {
        
            if (pos >= start)
                return 1;
        }

        return 0;
    }

    
    for (int i = start; i <= n - (k - depth); i++)
    {
        if (findKSum(arr, n, k, T,
                     i + 1,
                     depth + 1,
                     sum + arr[i]))
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n, k, T;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *S = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter target T: ");
    scanf("%d", &T);

    if (k < 2 || k > n)
    {
        printf("Invalid value of k.\n");
        free(S);
        return 0;
    }

    /* Sort the set */
    mergeSort(S, 0, n - 1);

    printf("\nSorted set: ");

    for (int i = 0; i < n; i++)
        printf("%d ", S[i]);

    printf("\n");

    /* Find k elements whose sum is T */
    if (findKSum(S, n, k, T, 0, 0, 0))
        printf("YES: %d elements can be selected with sum %d.\n",
               k, T);
    else
        printf("NO: No %d elements have sum %d.\n",
               k, T);

    free(S);

    return 0;
}