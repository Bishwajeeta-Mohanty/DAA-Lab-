#include <stdio.h>

void selectionSort(int A[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main()
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    selectionSort(A, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}
