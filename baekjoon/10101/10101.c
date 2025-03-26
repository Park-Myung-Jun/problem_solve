#include <stdio.h>

#define TRIANBLE_SUM 180

int main(void)
{
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    if(A + B + C != TRIANBLE_SUM)
    {
        printf("Error\n");
    }
    else
    {
        if(A == B && B == C)
        {
            printf("Equilateral\n");
        }
        else if(A == B || B == C || C == A)
        {
            printf("Isosceles\n");
        }
        else
        {
            printf("Scalene\n");
        }
    }

    return 0;
}
