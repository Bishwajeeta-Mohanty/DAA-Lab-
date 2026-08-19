#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int point;
    int type;       // +1 = start, -1 = end
} Event;

int compareEvents(const void *a, const void *b)
{
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->point != e2->point)
        return e1->point - e2->point;

    return e2->type - e1->type;
}

void findMaximumPoint(int left[], int right[], int n)
{
    Event *events = (Event *)malloc(2 * n * sizeof(Event));

    for (int i = 0; i < n; i++)
    {
        events[2 * i].point = left[i];
        events[2 * i].type = +1;

        events[2 * i + 1].point = right[i];
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int current = 0;
    int maximum = 0;
    int bestPoint = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        current += events[i].type;

        if (current > maximum)
        {
            maximum = current;
            bestPoint = events[i].point;
        }
    }

    printf("\nPoint with maximum overlap = %d\n", bestPoint);
    printf("Maximum number of intervals = %d\n", maximum);

    free(events);
}

int main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int *left = (int *)malloc(n * sizeof(int));
    int *right = (int *)malloc(n * sizeof(int));

    printf("Enter left and right endpoints:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Interval %d: ", i + 1);
        scanf("%d %d", &left[i], &right[i]);
    }

    findMaximumPoint(left, right, n);

    free(left);
    free(right);

    return 0;
}