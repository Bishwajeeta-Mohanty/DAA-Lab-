#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    
    printf("Enter a sufficiently large value of n: ");
    scanf("%d", &n);

    printf("\nFunctions in increasing order of growth:\n\n");

    printf("1. 1/n\n");
    printf("2. log2(n)\n");
    printf("3. 12*sqrt(n)\n");
    printf("4. 50*sqrt(n)\n");
    printf("5. n^0.51\n");
    printf("6. 2^32 * n\n");
    printf("7. n*log2(n)\n");
    printf("8. n^2 - 324\n");
    printf("9. 100*n^2 + 6*n\n");
    printf("10. 2*n^3\n");
    printf("11. n^(log2(n))\n");
    printf("12. 3^n\n");

    printf("\nValues for n = %d:\n", n);

    printf("1/n              = %.10lf\n", 1.0/n);
    printf("log2(n)           = %.6lf\n", log2(n));
    printf("12*sqrt(n)        = %.6lf\n", 12*sqrt(n));
    printf("50*sqrt(n)        = %.6lf\n", 50*sqrt(n));
    printf("n^0.51            = %.6lf\n", pow(n, 0.51));
    printf("2^32*n            = %.6e\n", pow(2,32)*n);
    printf("n*log2(n)         = %.6lf\n", n*log2(n));
    printf("n^2 - 324         = %.6lf\n", (double)n*n - 324);
    printf("100*n^2 + 6*n     = %.6lf\n",
           100.0*n*n + 6*n);
    printf("2*n^3             = %.6lf\n", 2.0*n*n*n);
    printf("n^(log2(n))       = %.6e\n",
           pow(n, log2(n)));
    printf("3^n               = %.6e\n", pow(3,n));

    return 0;
}