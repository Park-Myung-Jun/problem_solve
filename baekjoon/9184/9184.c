#include <stdio.h>
#include <stdbool.h>

#define MAX_VALUE 101
#define VALUE_OFFSET 50

int g_dinamic_array[MAX_VALUE][MAX_VALUE][MAX_VALUE] = {0};

int recur_function(int a, int b, int c)
{
    int ret;

    //printf("%d %d %d\n", a, b, c);

    if(g_dinamic_array[a][b][c] != 0)
    {
        return g_dinamic_array[a][b][c];
    }

    if(a <= VALUE_OFFSET || b <= VALUE_OFFSET || c <= VALUE_OFFSET)
    {
        ret = 1;
        g_dinamic_array[a][b][c] = ret;
        return ret;
    }

    if(a > 20 + VALUE_OFFSET || b > 20  + VALUE_OFFSET || c > 20 + VALUE_OFFSET)
    {
        ret = recur_function(70, 70, 70);
        g_dinamic_array[a][b][c] = ret;
        return ret;
    }

    if(a < b && b < c)
    {
        ret = recur_function(a, b, c - 1) + recur_function(a, b - 1, c - 1) - recur_function(a, b - 1, c);
        g_dinamic_array[a][b][c] = ret;
        return ret;
    }

    ret = recur_function(a - 1, b, c) + recur_function(a - 1, b - 1, c) + recur_function(a - 1, b, c - 1) - recur_function(a - 1, b - 1, c - 1);
    g_dinamic_array[a][b][c] = ret;
    return ret;
}

int main(void)
{
    int a, b, c;

    while(true)
    {
        scanf("%d %d %d", &a, &b, &c);

        if(a == -1 && b == -1 && c == -1)
        {
            break;
        }

        printf("w(%d, %d, %d) = %d\n", a, b, c, recur_function(a + VALUE_OFFSET, b + VALUE_OFFSET, c + VALUE_OFFSET));
    }

    return 0;
}
