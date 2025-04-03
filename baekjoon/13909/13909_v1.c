#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    int N, sqrt_num, count;

    scanf("%d", &N);
    count = 0;

    for(i = 1; i <= N; i++)
    {
        sqrt_num = (int)sqrt(i);
        if(sqrt_num * sqrt_num == i)
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
