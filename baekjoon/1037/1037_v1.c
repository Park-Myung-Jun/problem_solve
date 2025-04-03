#include <stdio.h>
#include <stdbool.h>

#define DIVISOR_MAX 50
#define FIND_N_MAX 1000000

int main(void)
{
    int i, j;
    int N;
    int divisor[DIVISOR_MAX];
    bool is_all_divisor, is_find;

    scanf("%d\n", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", divisor + i);
    }

    for(i = 2; i <= FIND_N_MAX; i++)
    {
        is_all_divisor = true;
        is_find = false;

        for(j = 0; j < N; j++)
        {
            if(i % divisor[j] != 0)
            {
                is_all_divisor = false;
                break;
            }
        }

        if(is_all_divisor)
        {
            for(j = 0; j < N; j++)
            {
                if(divisor[j] == i)
                {
                    is_find = true;
                    break;
                }
            }

            if(is_find == true)
            {
                continue;
            }

            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
