#include <stdio.h>
#include <string.h>

#define NUM_MAX_VALUE 10000

int main(void)
{
    int i;
    int N, num_get;
    int num_array[NUM_MAX_VALUE];

    memset(num_array, 0x00, sizeof(int) * NUM_MAX_VALUE);

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &num_get);
        num_array[num_get - 1]++;
    }

    for(i = 0; i < NUM_MAX_VALUE; i++)
    {
        if(num_array[i] != 0)
        {
            printf("%d\n", i + 1);
            num_array[i]--;
            i--;
        }
    }

    return 0;
}
