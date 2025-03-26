#include <stdio.h>

int main(void)
{
    int i;
    int A, B, C, D;
    int up, down;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    up = A * D + C * B;
    down = B * D;

    for(i = 2; i <= up && i <= down; i++)
    {
        if(up % i == 0 && down % i == 0)
        {
            up /= i;
            down /= i;
            i--;
        }
    }

    printf("%d %d\n", up, down);

    return 0;
}
