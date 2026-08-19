#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int time;
    int type;       // +1 = entry, -1 = exit
} Event;

int compareEvents(const void *a, const void *b)
{
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    return e1->time - e2->time;
}

void findMaximumPeople(int entry[], int exit[], int n)
{
    Event *events = (Event *)malloc(2 * n * sizeof(Event));

    for (int i = 0; i < n; i++)
    {
        events[2 * i].time = entry[i];
        events[2 * i].type = +1;

        events[2 * i + 1].time = exit[i];
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(Event), compareEvents);

    int current = 0;
    int maximum = 0;
    int maximumTime = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        current += events[i].type;

        if (current > maximum)
        {
            maximum = current;
            maximumTime = events[i].time;
        }
    }

    printf("\nMaximum number of people present = %d\n", maximum);
    printf("Time when maximum people were present = %d\n",
           maximumTime);

    free(events);
}

int main()
{
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    int *entry = (int *)malloc(n * sizeof(int));
    int *exit = (int *)malloc(n * sizeof(int));

    printf("\nEnter entry and exit time for each person:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Person %d: ", i + 1);
        scanf("%d %d", &entry[i], &exit[i]);
    }

    findMaximumPeople(entry, exit, n);

    free(entry);
    free(exit);

    return 0;
}