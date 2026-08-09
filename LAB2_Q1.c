#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 50000
#define STEP 5000


void print_header(FILE *fp)
{
    fprintf(fp, "n,search,insert,delete,maximum,minimum,predecessor,successor\n");
}


void unsorted_array(FILE *fp)
{
    int n, i;
    print_header(fp);

    for (n = STEP; n <= MAX_N; n += STEP)
    {
        long long search = n;
        long long insert = 1;
        long long delete = n;
        long long maximum = n;
        long long minimum = n;
        long long predecessor = n;
        long long successor = n;

        fprintf(fp, "%d,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
                n, search, insert, delete, maximum,
                minimum, predecessor, successor);
    }
}

void sorted_array(FILE *fp)
{
    int n;
    print_header(fp);

    for (n = STEP; n <= MAX_N; n += STEP)
    {
        long long search = 1;

        int temp = n;
        while (temp > 1)
        {
            search++;
            temp /= 2;
        }

        long long insert = n;
        long long delete = n;
        long long maximum = 1;
        long long minimum = 1;
        long long predecessor = 1;
        long long successor = 1;

        fprintf(fp, "%d,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
                n, search, insert, delete, maximum,
                minimum, predecessor, successor);
    }
}


void singly_unsorted(FILE *fp)
{
    int n;
    print_header(fp);

    for (n = STEP; n <= MAX_N; n += STEP)
    {
        long long search = n;
        long long insert = 1;
        long long delete = n;
        long long maximum = n;
        long long minimum = n;
        long long predecessor = n;
        long long successor = n;

        fprintf(fp, "%d,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
                n, search, insert, delete, maximum,
                minimum, predecessor, successor);
    }
}

void singly_sorted(FILE *fp)
{
    int n;
    print_header(fp);

    for (n = STEP; n <= MAX_N; n += STEP)
    {
        long long search = n;
        long long insert = n;
        long long delete = n;
        long long maximum = 1;
        long long minimum = 1;
        long long predecessor = n;
        long long successor = 1;

        fprintf(fp, "%d,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
                n, search, insert, delete, maximum,
                minimum, predecessor, successor);
    }
}

void doubly_unsorted(FILE *fp)
{
    int n;
    print_header(fp);

    for (n = STEP; n <= MAX_N; n += STEP)
    {
        long long search = n;
        long long insert = 1;
        long long delete = 1;
        long long maximum = n;
        long long minimum = n;
        long long predecessor = n;
        long long successor = n;

        fprintf(fp, "%d,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
                n, search, insert, delete, maximum,
                minimum, predecessor, successor);
    }
}

void doubly_sorted(FILE *fp)
{
    int n;
    print_header(fp);

    for (n = STEP; n <= MAX_N; n += STEP)
    {
        long long search = n;
        long long insert = n;
        long long delete = 1;
        long long maximum = 1;
        long long minimum = 1;
        long long predecessor = 1;
        long long successor = 1;

        fprintf(fp, "%d,%lld,%lld,%lld,%lld,%lld,%lld,%lld\n",
                n, search, insert, delete, maximum,
                minimum, predecessor, successor);
    }
}

int main()
{
    FILE *fp;

    fp = fopen("unsorted_array.csv", "w");
    unsorted_array(fp);
    fclose(fp);

    fp = fopen("sorted_array.csv", "w");
    sorted_array(fp);
    fclose(fp);

    fp = fopen("singly_unsorted.csv", "w");
    singly_unsorted(fp);
    fclose(fp);

    fp = fopen("singly_sorted.csv", "w");
    singly_sorted(fp);
    fclose(fp);

    fp = fopen("doubly_unsorted.csv", "w");
    doubly_unsorted(fp);
    fclose(fp);

    fp = fopen("doubly_sorted.csv", "w");
    doubly_sorted(fp);
    fclose(fp);

    printf("Data generated successfully!\n");
    printf("CSV files created for all six data structures.\n");

    return 0;
}