#include <stdio.h>
#include <string.h>

typedef struct {
    int number;
    char colour;
} Item;

void colourSort(Item A[], int n)
{
    Item red[n], blue[n], yellow[n];

    int r = 0, b = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i].colour == 'R')
            red[r++] = A[i];

        else if (A[i].colour == 'B')
            blue[b++] = A[i];

        else if (A[i].colour == 'Y')
            yellow[y++] = A[i];
    }

    for (int i = 0; i < r; i++)
        printf("(%d, Red) ", red[i].number);

    for (int i = 0; i < b; i++)
        printf("(%d, Blue) ", blue[i].number);

    for (int i = 0; i < y; i++)
        printf("(%d, Yellow) ", yellow[i].number);

    printf("\n");
}

int main()
{
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item A[n];

    printf("Enter number and colour (R/B/Y):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &A[i].number, &A[i].colour);
    }

    printf("\nSorted by colour:\n");
    colourSort(A, n);

    return 0;
}
