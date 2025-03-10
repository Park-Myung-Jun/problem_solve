#include <stdio.h>

#define NUM_BUFFER_SIZE 9

int main(void)
{
    int i, j;
    int max_num, max_num_i, max_num_j, get_num;

    max_num = 0;
    get_num = 0;
    for(i = 0; i < NUM_BUFFER_SIZE; i++)
    {
        for(j = 0; j < NUM_BUFFER_SIZE; j++)
        {
            scanf("%d", &get_num);

            if(max_num <= get_num)
            {
                max_num = get_num;
                max_num_i = i;
                max_num_j = j;
            }
        }
    }

    printf("%d\n%d %d\n", max_num, max_num_i + 1, max_num_j + 1);

    return 0;
}