#include <stdio.h>
#include <string.h>

#define GIVEN_NUM 10
#define DIVIDE_NUM 42

int main(void)
{
    int i;
    int get_num, rest_num[DIVIDE_NUM], count_num;

    count_num = 0;
    memset(rest_num, 0x00, DIVIDE_NUM * sizeof(int));
    for(i = 0; i < GIVEN_NUM; i++)
    {
        scanf("%d", &get_num);
        rest_num[(get_num - 1) % DIVIDE_NUM]++;
    }

    for(i = 0; i < DIVIDE_NUM; i++)
    {
        if(rest_num[i] != 0)
        {
            count_num++;
        }
    }

    printf("%d\n", count_num);

    return 0;
}
