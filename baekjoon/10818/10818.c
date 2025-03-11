#include <stdio.h>

int main(void)
{
    int i;
    int N, num_get;
    int num_max, num_min;

    num_max = -1000000;
    num_min = 1000000;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &num_get);

        if(num_get < num_min)
        {
            num_min = num_get;
        }

        if(num_max < num_get)
        {
            num_max = num_get;
        }
    }

    printf("%d %d\n", num_min, num_max);

    return 0;
}