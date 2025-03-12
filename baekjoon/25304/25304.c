#include <stdio.h>

int main(void)
{
    int X, N, a, b;
    int i;

    scanf("%d %d", &X, &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        X -= (a * b);
    }

    if(X == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}