#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SET_MAX 200000

int algo_function(const void* p_a, const void* p_b)
{
    int a = *(int*)p_a;
    int b = *(int*)p_b;

    return (a > b) - (a < b);
}

int main(void)
{
    int i;
    int a_size, b_size;
    int a_set[SET_MAX], b_set[SET_MAX];
    int *a_set_ptr, union_count;

    memset(a_set, 0x00, sizeof(int) * SET_MAX);
    memset(b_set, 0x00, sizeof(int) * SET_MAX);

    scanf("%d %d", &a_size, &b_size);
    for(i = 0; i < a_size; i++)
    {
        scanf("%d", a_set + i);
    }
    for(i = 0; i < b_size; i++)
    {
        scanf("%d", b_set + i);
    }

    qsort(a_set, a_size, sizeof(int), algo_function);
    qsort(b_set, b_size, sizeof(int), algo_function);

    union_count = 0;
    for(i = 0; i < a_size; i++)
    {
        a_set_ptr = bsearch(a_set + i, b_set, b_size, sizeof(int), algo_function);

        if(a_set_ptr != NULL)
        {
            union_count++;
        }
    }

    printf("%d\n", a_size + b_size - union_count - union_count);

    return 0;
}
