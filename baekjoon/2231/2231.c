#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool is_production_num_able;
    int i, j;
    int N, production_num, digit_sum;
    scanf("%d", &N);

    is_production_num_able = false;
    for(i = 1; i < N; i++)
    {
        production_num = i;
        digit_sum = i;

        while(production_num)
        {
            digit_sum += production_num % 10;
            production_num /= 10;
        }

        if(digit_sum == N)
        {
            printf("%d\n", i);
            is_production_num_able = true;
            break;
        }
    }

    if(is_production_num_able == false)
    {
        printf("0\n");
    }

    return 0;
}
