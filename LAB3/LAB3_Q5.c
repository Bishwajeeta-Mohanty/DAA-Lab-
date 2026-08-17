#include <stdio.h>
#include <stdlib.h>

long long recursiveMultiplications = 0;

int **allocateMatrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    return matrix;
}

void freeMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);

    free(matrix);
}

void addMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/*
    Special Matrix Multiplication

    A = [ A1  A2 ]
        [ A2  A1 ]

    B = [ B1  B2 ]
        [ B2  B1 ]
*/
void specialMultiply(int **A, int **B, int **C, int n)
{

    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        recursiveMultiplications++;
        return;
    }

    int m = n / 2;

    int **A1 = allocateMatrix(m);
    int **A2 = allocateMatrix(m);

    int **B1 = allocateMatrix(m);
    int **B2 = allocateMatrix(m);

    int **Aplus = allocateMatrix(m);
    int **Aminus = allocateMatrix(m);

    int **Bplus = allocateMatrix(m);
    int **Bminus = allocateMatrix(m);

    int **R = allocateMatrix(m);
    int **S = allocateMatrix(m);

    int **P = allocateMatrix(m);
    int **Q = allocateMatrix(m);

    /*
        Extract A1 and A2

        A = [ A1 A2 ]
            [ A2 A1 ]
    */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + m];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + m];
        }
    }

    /*
        Aplus  = A1 + A2
        Aminus = A1 - A2
    */
    addMatrix(A1, A2, Aplus, m);
    subtractMatrix(A1, A2, Aminus, m);

    /*
        Bplus  = B1 + B2
        Bminus = B1 - B2
    */
    addMatrix(B1, B2, Bplus, m);
    subtractMatrix(B1, B2, Bminus, m);

    /*
        R = (A1 + A2)(B1 + B2)
    */
    specialMultiply(Aplus, Bplus, R, m);

    /*
        S = (A1 - A2)(B1 - B2)
    */
    specialMultiply(Aminus, Bminus, S, m);

    /*
        P = (R + S) / 2
        Q = (R - S) / 2
    */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            P[i][j] = (R[i][j] + S[i][j]) / 2;
            Q[i][j] = (R[i][j] - S[i][j]) / 2;
        }
    }

    /*
        Construct:

        C = [ P Q ]
            [ Q P ]
    */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            C[i][j] = P[i][j];
            C[i][j + m] = Q[i][j];

            C[i + m][j] = Q[i][j];
            C[i + m][j + m] = P[i][j];
        }
    }

    freeMatrix(A1, m);
    freeMatrix(A2, m);
    freeMatrix(B1, m);
    freeMatrix(B2, m);

    freeMatrix(Aplus, m);
    freeMatrix(Aminus, m);
    freeMatrix(Bplus, m);
    freeMatrix(Bminus, m);

    freeMatrix(R, m);
    freeMatrix(S, m);
    freeMatrix(P, m);
    freeMatrix(Q, m);
}

void printMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the size of matrix (power of 2): ");
    scanf("%d", &n);

    int **A = allocateMatrix(n);
    int **B = allocateMatrix(n);
    int **C = allocateMatrix(n);

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

    recursiveMultiplications = 0;

    specialMultiply(A, B, C, n);

    printf("\nResultant Matrix:\n");
    printMatrix(C, n);

    printf("\nNumber of base-case multiplications: %lld\n",
           recursiveMultiplications);

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}