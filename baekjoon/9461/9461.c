#include <stdio.h>

#define WAVE_MAX 101

int main(void)
{
    int i;
    int T, N;
    long long int wave_array[WAVE_MAX] = {0, 1, 1, 1, 2, 2};

    for(i = 6; i < WAVE_MAX; i++)
    {
        wave_array[i] = wave_array[i - 1] + wave_array[i - 5];
    }

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        printf("%lld\n", wave_array[N]);
    }

    return 0;
}
