#include <stdio.h>
#include <string.h>

#define NUM_MAX_SIZE 101

int main(void)
{
    int i;
    int N, sum;
    char num_array[NUM_MAX_SIZE];

    sum = 0;
    memset(num_array, 0x00, NUM_MAX_SIZE * sizeof(char));

#if 1
    scanf("%d %s", &N, num_array);
#else
    scanf("%d", &N);
    while(getchar() != '\n')
    {
        continue;
    }
    scanf("%s", num_array);
#endif

    for(i = 0; i < N; i++)
    {
        sum += (num_array[i] - '0');
    }

    printf("%d\n", sum);

    return 0;
}