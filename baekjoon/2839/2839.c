#include <stdio.h>

int main(void)
{
    int i;
    int N, count, min_bag = 2000;

    scanf("%d", &N);

    for(i = 0; i * 5 <= N; i++)
    {
        if((N - i * 5) % 3 != 0)
        {
            continue;
        }

        count = (N - i * 5) / 3 + i;
        if(count < min_bag)
        {
            min_bag = count;
        }
    }

    if(min_bag != 2000)
    {
        printf("%d\n", min_bag);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
