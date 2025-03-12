#include <stdio.h>

int main(void)
{
    int mapping_quadrant[4] = {1, 2, 4, 3};
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%d\n", mapping_quadrant[(y < 0) * 2 + (x < 0)]);

    return 0;
}