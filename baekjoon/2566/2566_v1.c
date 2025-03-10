#include <stdio.h>
#include <string.h>

#define NUM_BUFFER_SIZE 9

void find_max_num(int nb[][NUM_BUFFER_SIZE], int* mn, int* mni, int* mnj)
{
    int i, j;
    for(i = 0; i < NUM_BUFFER_SIZE; i++)
    {
        for(j = 0; j < NUM_BUFFER_SIZE; j++)
        {
            if(*mn <= nb[i][j])
            {
                *mn = nb[i][j];
                *mni = i;
                *mnj = j;
            }
        }
    }
}

int main(void)
{
    int i, j;
    int num_buffer[NUM_BUFFER_SIZE][NUM_BUFFER_SIZE];
    int max_num, max_num_i, max_num_j;

    for(i = 0; i < NUM_BUFFER_SIZE; i++)
    {
        memset(num_buffer[i], 0x00, NUM_BUFFER_SIZE * sizeof(int));

        for(j = 0; j < NUM_BUFFER_SIZE; j++)
        {
            scanf("%d", num_buffer[i] + j);
        }
    }
    max_num = 0;

    find_max_num(num_buffer, &max_num, &max_num_i, &max_num_j);

    printf("%d\n%d %d\n", max_num, max_num_i + 1, max_num_j + 1);

    return 0;
}