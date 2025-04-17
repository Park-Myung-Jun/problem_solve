#include <stdio.h>

int cantor(int num, int hole)
{
    if(num == 0)
    {
        if(hole == 0)
        {
            printf(" ");
        }
        else
        {
            printf("-");
        }
    }
    else
    {
        if(hole == 0)
        {
            cantor(num - 1, 0);
            cantor(num - 1, 0);
            cantor(num - 1, 0);
        }
        else
        {
            cantor(num - 1, 1);
            cantor(num - 1, 0);
            cantor(num - 1, 1);
        }
    }
}

int main(void)
{
    int N;

    while(scanf("%d", &N) != EOF)
    {
        cantor(N, 1);
        printf("\n");
    }

    return 0;
}
