#include <stdio.h>

int findPartitionPoint(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int answer = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1)
        {
            
            answer = mid;

            
            high = mid - 1;
        }
        else
        {
            
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int n;

    printf("FIND PARTITION POINT\n");
    printf("--------------------\n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter elements (only 0 and 1):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if (arr[i] != 0 && arr[i] != 1)
        {
            printf("Only 0 and 1 are allowed.\n");
            return 1;
        }
    }

    int partition = findPartitionPoint(arr, n);

    printf("\nArray:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    if (partition == 0)
    {
        printf("All elements are 1.\n");
        printf("Partition point = 0\n");
    }
    else if (partition == n)
    {
        printf("All elements are 0.\n");
        printf("No 1 found.\n");
        printf("Partition point = %d\n", n);
    }
    else
    {
        printf("Partition point = %d\n", partition);
        printf("First 1 occurs at index %d.\n", partition);
        printf("Number of zeros = %d\n", partition);
        printf("Number of ones = %d\n", n - partition);
    }

    return 0;
}