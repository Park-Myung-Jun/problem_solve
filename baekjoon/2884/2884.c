#include <stdio.h>

int main(void)
{
    int H, M, time_min;

    scanf("%d %d", &H, &M);

    time_min = H * 60 + M - 45;
    if(time_min < 0)
    {
        time_min += 1440;
    }

    printf("%d %d\n", time_min / 60, time_min % 60);

    return 0;
}