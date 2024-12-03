#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
    float  temp, lambda_new, lambda_old, error;
    
    int i, j, n , step=1;

    /*inputs*/

    printf("Enter the order of your matrix: ");
    scanf("%d", &n);
    printf("Enter error margin: ");
    scanf("%f", &error);

    /*reading matrix*/
    printf("Enter coefficient of matrix: \n");
    for (i =1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* reading initial guess vector */
    printf("Enter initial guess vector: \n");
    for (i=1; i<=n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }
    
    /* Initializing lambda_old */

    lambda_old = 1;

    /* Multiplication */
    up:
    for (i=1; i<=n; i++)
    {
        temp = 0.0;
        for (j=1; j<=n; j++)
        {
            temp = temp + a[i][j]*x[j];
        }
        x_new[i] = temp;
    } 

    /* Replacing */
    for (i=1; i<=n; i++)
    {
        x[i] = x_new[i];
    }

    /* Finding Largest */
    lambda_new = fabs(x[1]);
    for (i=2; i<n; i++) 
    {
        if (fabs(x[i]) > lambda_new)
        {
            lambda_new = fabs(x[i]);
        }
    }

    /* Normalization */
    for (i=1; i<=n; i++) 
    {
        x[i] = x[i]/lambda_new;
    }

    /* Display */
    printf("\n\nSTEP-%d:\n", step);
    printf("Eigen Value = %f\n");
    printf("Eigen Vector: \n");
    for (i=1; i<=n; i++)
    {
        printf("%f\t", x[i]);
    }
    
    /* Checking Accuracy */
    if (fabs(lambda_new - lambda_old) > error)
    {
        lambda_old = lambda_new;
        step++;
        goto up;
    }

    getchar();
    return (0);

}
