#include <stdio.h>

unsigned long long moveCount = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 0)
        return;

    towerOfHanoi(n - 1, source, destination, auxiliary);

    moveCount++;

    printf("Move disk %d from %c -> %c\n",
           n, source, destination);

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("TOWERS OF HANOI\n");
    printf("----------------\n");

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Please enter n between 1 and 20.\n");
        return 1;
    }

    moveCount = 0;

    towerOfHanoi(n, 'A', 'B', 'C');

    printf("\nTotal number of moves = %llu\n", moveCount);

    printf("Expected number of moves = 2^%d - 1 = %llu\n",
           n, (1ULL << n) - 1);

    return 0;
}