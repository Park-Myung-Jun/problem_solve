#include <stdio.h>
#include <string.h>

#define NUM_GET_SIZE 9

int main(void)
{
    int i;
    int num[NUM_GET_SIZE], num_max, position;

    memset(num, 0x00, NUM_GET_SIZE);
    num_max = 0;
    position = 0;

    for(i = 0; i < NUM_GET_SIZE; i++)
    {
        scanf("%d", num + i);
    }

    for(i = 0; i < NUM_GET_SIZE; i++)
    {
        if(num_max < num[i])
        {
            num_max = num[i];
            position = i + 1;
        }
    }

    printf("%d\n%d\n", num_max, position);

    return 0;
}