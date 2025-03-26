#include <stdio.h>

#define DOT_SIZE 100000
#define AREA_MAX 10000

int main(void)
{
    int i;
    int N, x_get, y_get;
    int x_left = AREA_MAX, x_right= -AREA_MAX, y_up = -AREA_MAX, y_down = AREA_MAX;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%d %d", &x_get, &y_get);

        if(x_get < x_left)
        {
            x_left = x_get;
        }

        if(x_right < x_get)
        {
            x_right = x_get;
        }

        if(y_get < y_down)
        {
            y_down = y_get;
        }

        if(y_up < y_get)
        {
            y_up = y_get;
        }
    }

    printf("%d\n", (x_right - x_left) * (y_up - y_down));

    return 0;
}
