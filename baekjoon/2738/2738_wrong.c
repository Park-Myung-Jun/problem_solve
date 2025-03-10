#include <stdio.h>
#include <string.h>

#define MATRIX_MAX_SIZE 100

int main(void)
{
    int i, j;
    int N, M, A[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], B[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++)
    {
        memset(A[i], 0x00, MATRIX_MAX_SIZE);

        for(j = 0; j < N; j++)
        {
            scanf("%d", A[i] + j);
        }
    }
    for(i = 0; i < M; i++)
    {
        memset(B[i], 0x00, MATRIX_MAX_SIZE);

        for(j = 0; j < M; j++)
        {
            scanf("%d", B[i] + j);
        }
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            A[i][j] += B[i][j];
        }
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }

        printf("\n");
    }

    return 0;
}