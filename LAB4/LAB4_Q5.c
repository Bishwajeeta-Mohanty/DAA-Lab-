#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} Interval;

int compareIntervals(const void *a, const void *b)
{
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;

    return i1->start - i2->start;
}

void mergeIntervals(Interval intervals[], int n)
{
    if (n == 0)
        return;

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    printf("\nSorted intervals:\n");

    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", intervals[i].start,
               intervals[i].end);
    }

    printf("\n\nMerged intervals:\n");

    int start = intervals[0].start;
    int end = intervals[0].end;

    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start <= end)
        {
            if (intervals[i].end > end)
                end = intervals[i].end;
        }
        else
        {
            printf("(%d, %d) ", start, end);

            start = intervals[i].start;
            end = intervals[i].end;
        }
    }

    printf("(%d, %d)\n", start, end);
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval *intervals =
        (Interval *)malloc(n * sizeof(Interval));

    printf("Enter intervals (start end):\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",
              &intervals[i].start,
              &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    free(intervals);

    return 0;
}