#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USE_LOG 0

#define POINT_MAX_SIZE 1000000

int point_origin[POINT_MAX_SIZE];
int point_sort[POINT_MAX_SIZE];

int algo_function(const void* p_a, const void* p_b)
{
    int a = *(const int*)p_a;
    int b = *(const int*)p_b;

    return (a > b) - (a < b);
}

int main(void)
{
    int i;
    int N, zip, zip_index;

    scanf("%d", &N);
    memset(point_origin, 0x00, sizeof(int) * POINT_MAX_SIZE);
    memset(point_sort, 0x00, sizeof(int) * POINT_MAX_SIZE);
    zip = 0;
    zip_index = 0;

    for(i = 0; i < N; i++)
    {
        scanf("%d", point_origin + i);
        point_sort[i] = point_origin[i];
    }

    qsort(point_sort, N, sizeof(int), algo_function);

#if USE_LOG
    for(i = 0; i < N; i++)
    {
        printf("%d ", point_sort[i]);
    }
    printf("\n");
#endif

    zip = point_sort[0];
    zip_index++;
    for(i = 1; i < N; i++)
    {
        if(zip != point_sort[i])
        {
            point_sort[zip_index] = point_sort[i];
            zip = point_sort[i];
            zip_index++;
        }
    }

#if USE_LOG
    for(i = 0; i < zip_index; i++)
    {
        printf("%d ", point_sort[i]);
    }
    printf("%d\n", zip_index);
#endif

    for(i = 0; i < N; i++)
    {
        printf("%d ", (int*)bsearch(point_origin + i, point_sort, zip_index, sizeof(int), algo_function) - point_sort);
    }
    printf("\n");

    return 0;
}
