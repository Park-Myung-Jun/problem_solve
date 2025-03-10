#include <stdio.h>
#include <string.h>

#define ARRAY_MAX_SIZE 10000

int main(void)
{
    int N, X, nums[ARRAY_MAX_SIZE];
    int i;

    //init
    scanf("%d %d", &N, &X);
    memset(nums, 0x00, ARRAY_MAX_SIZE * sizeof(int));
    for(i = 0; i < N; i++)
    {
        scanf("%d", nums + i);
    }

    for(i = 0; i < N; i++)
    {
        if(nums[i] < X)
        {
            printf("%d ", nums[i]);
        }
    }
    printf("\n");

    return 0;
}