#include <stdio.h>

#define TILE_MAX 1000001
#define DIV_VALUE 15746

int tiles[TILE_MAX] = {0, 1, 2};

int main(void)
{
    int N, i;

    scanf("%d", &N);

    tiles[0] = 0;
    tiles[1] = 1;
    tiles[2] = 2;

    for(i = 3; i <= N; i++)
    {
        tiles[i] = (tiles[i - 1] + tiles[i - 2]) % DIV_VALUE;
    }

    printf("%d\n", tiles[N]);

    return 0;
}
