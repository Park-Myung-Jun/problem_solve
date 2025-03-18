#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SUBMULTIPLE_SAVE_MAX 50000

void Is_Perfect_Num(int num)
{
    int i;
    int submultiple_save[SUBMULTIPLE_SAVE_MAX] = {0}, submultiple_save_count = 0;
    int sum = 0;

    for(i = 1; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            submultiple_save[submultiple_save_count] = i;
            submultiple_save_count++;
        }
    }

    for(i = 0; i < submultiple_save_count; i++)
    {
        sum += submultiple_save[i];
    }

    if(sum == num)
    {
        printf("%d = %d", num, submultiple_save[0]);
        for(i = 1; i < submultiple_save_count; i++)
        {
            printf(" + %d", submultiple_save[i]);
        }
        printf("\n");
    }
    else
    {
        printf("%d is NOT perfect.\n", num);
    }
}

int main(void)
{
    int n, get_num;

    while(true)
    {
        scanf("%d", &n);
        if(n == -1)
        {
            break;
        }

        Is_Perfect_Num(n);
    }

    return 0;
}
