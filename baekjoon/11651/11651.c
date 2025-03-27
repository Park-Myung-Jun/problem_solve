#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define POINT_MAX_SIZE 100000

typedef struct _tsPoint {
    int y;
    int x;
} tsPoint;

int algo_function(const void* a, const void* b)
{
    tsPoint l = *(tsPoint const*)a;
    tsPoint r = *(tsPoint const*)b;

    int y_compare;

    y_compare = (l.y > r.y) - (l.y < r.y);

    if(y_compare != 0)
    {
        return y_compare;
    }
    else
    {
        return (l.x > r.x) - (l.x < r.x);
    }
}

int main(void)
{
    int i;
    int N, x_get, y_get;
    tsPoint point[POINT_MAX_SIZE];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d %d", &point[i].x, &point[i].y);
    }

    qsort(point, N, sizeof(tsPoint), algo_function);

    for(i = 0; i < N; i++)
    {
        printf("%d %d\n", point[i].x, point[i].y);
    }

    return 0;
}
