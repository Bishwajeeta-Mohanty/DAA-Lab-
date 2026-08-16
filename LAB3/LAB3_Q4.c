#include <stdio.h>
#include <stdlib.h>

void addMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int **A, int **B, int **C, int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int **A11 = malloc(newSize * sizeof(int *));
    int **A12 = malloc(newSize * sizeof(int *));
    int **A21 = malloc(newSize * sizeof(int *));
    int **A22 = malloc(newSize * sizeof(int *));

    int **B11 = malloc(newSize * sizeof(int *));
    int **B12 = malloc(newSize * sizeof(int *));
    int **B21 = malloc(newSize * sizeof(int *));
    int **B22 = malloc(newSize * sizeof(int *));

    int **M1 = malloc(newSize * sizeof(int *));
    int **M2 = malloc(newSize * sizeof(int *));
    int **M3 = malloc(newSize * sizeof(int *));
    int **M4 = malloc(newSize * sizeof(int *));
    int **M5 = malloc(newSize * sizeof(int *));
    int **M6 = malloc(newSize * sizeof(int *));
    int **M7 = malloc(newSize * sizeof(int *));

    int **temp1 = malloc(newSize * sizeof(int *));
    int **temp2 = malloc(newSize * sizeof(int *));

    for (int i = 0; i < newSize; i++)
    {
        A11[i] = malloc(newSize * sizeof(int));
        A12[i] = malloc(newSize * sizeof(int));
        A21[i] = malloc(newSize * sizeof(int));
        A22[i] = malloc(newSize * sizeof(int));

        B11[i] = malloc(newSize * sizeof(int));
        B12[i] = malloc(newSize * sizeof(int));
        B21[i] = malloc(newSize * sizeof(int));
        B22[i] = malloc(newSize * sizeof(int));

        M1[i] = malloc(newSize * sizeof(int));
        M2[i] = malloc(newSize * sizeof(int));
        M3[i] = malloc(newSize * sizeof(int));
        M4[i] = malloc(newSize * sizeof(int));
        M5[i] = malloc(newSize * sizeof(int));
        M6[i] = malloc(newSize * sizeof(int));
        M7[i] = malloc(newSize * sizeof(int));

        temp1[i] = malloc(newSize * sizeof(int));
        temp2[i] = malloc(newSize * sizeof(int));
    }

    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    /* M1 = (A11 + A22) * (B11 + B22) */
    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    /* M2 = (A21 + A22) * B11 */
    addMatrix(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    /* M3 = A11 * (B12 - B22) */
    subMatrix(B12, B22, temp2, newSize);
    strassen(A11, temp2, M3, newSize);

    /* M4 = A22 * (B21 - B11) */
    subMatrix(B21, B11, temp2, newSize);
    strassen(A22, temp2, M4, newSize);

    /* M5 = (A11 + A12) * B22 */
    addMatrix(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    /* M6 = (A21 - A11) * (B11 + B12) */
    subMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    /* M7 = (A12 - A22) * (B21 + B22) */
    subMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    /* C11 = M1 + M4 - M5 + M7 */
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] =
                M1[i][j] + M4[i][j]
                - M5[i][j] + M7[i][j];

            /* C12 = M3 + M5 */
            C[i][j + newSize] =
                M3[i][j] + M5[i][j];

            /* C21 = M2 + M4 */
            C[i + newSize][j] =
                M2[i][j] + M4[i][j];

            /* C22 = M1 - M2 + M3 + M6 */
            C[i + newSize][j + newSize] =
                M1[i][j] - M2[i][j]
                + M3[i][j] + M6[i][j];
        }
    }


    int ***matrices[] = {
        &A11, &A12, &A21, &A22,
        &B11, &B12, &B21, &B22,
        &M1, &M2, &M3, &M4,
        &M5, &M6, &M7,
        &temp1, &temp2
    };

    for (int k = 0; k < 17; k++)
    {
        for (int i = 0; i < newSize; i++)
            free((*matrices[k])[i]);

        free(*matrices[k]);
    }
}

int **allocateMatrix(int n)
{
    int **matrix = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        matrix[i] = malloc(n * sizeof(int));

    return matrix;
}

void freeMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
}

int main()
{
    int n;

    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    int size = 1;

    while (size < n)
        size *= 2;

    int **A = allocateMatrix(size);
    int **B = allocateMatrix(size);
    int **C = allocateMatrix(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = 0;
            B[i][j] = 0;
            C[i][j] = 0;
        }
    }

    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, size);

    printf("\nResultant Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}