#include <stdio.h>

#define DISTANCE_MAX 1000
#define DISTANCE_DIRECTION 4

int main(void)
{
    int i;
    int distance_max = DISTANCE_MAX, distance_diff;
    int x, y, w, h, distance_data[DISTANCE_DIRECTION];
    scanf("%d %d %d %d", &x, &y, &w, &h);

    distance_data[0] = x;
    distance_data[1] = y;
    distance_data[2] = w - x;
    distance_data[3] = h - y;

    for(i = 0; i < 4; i++)
    {
        distance_diff = distance_data[i];
        if(distance_diff < distance_max)
        {
            distance_max = distance_diff;
        }
    }

    printf("%d\n", distance_max);

    return 0;
}
