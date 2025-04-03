#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    int N, sqrt_num, count;

    scanf("%d", &N);
    count = 0;

    sqrt_num = (int)sqrt(N);
    for(i = 1; i <= sqrt_num; i++)
    {
        if(i * i <= N)
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
