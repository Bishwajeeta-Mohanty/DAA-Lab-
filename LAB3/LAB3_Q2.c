#include <stdio.h>

int findDefective(int coins[], int left, int right)
{
    if (left == right)
        return left;

    int n = right - left + 1;

    if (n == 2)
    {
        if (coins[left] < coins[right])
            return left;

        if (coins[right] < coins[left])
            return right;

        return -1; 
    }

    int mid = (left + right) / 2;

    int leftSum = 0;
    int rightSum = 0;

    for (int i = left; i <= mid; i++)
        leftSum += coins[i];

    for (int i = mid + 1; i <= right; i++)
        rightSum += coins[i];

    if (leftSum < rightSum)
        return findDefective(coins, left, mid);

    if (rightSum < leftSum)
        return findDefective(coins, mid + 1, right);

    return -1;
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter weights of coins:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    int result = findDefective(coins, 0, n - 1);

    if (result == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin is at index %d.\n", result);

    return 0;
}
