#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STAR_MAX 6561

bool star_map[STAR_MAX][STAR_MAX];

void star_recursive(int y, int x, int size, bool check)
{
    int i, j;

    if(size == 1)
    {
        star_map[y][x] = check;
        return;
    }

    size /= 3;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(check == true && (i != 1 || j != 1))
            {
                star_recursive(y + size * i, x + size * j, size, true);
            }
            else
            {
                star_recursive(y + size * i, x + size * j, size, false);
            }
        }
    }
}

int main(void)
{
    int i, j;
    int N;

    for(i = 0; i < STAR_MAX; i++)
    {
        memset(star_map[i], 0x00, sizeof(bool) * STAR_MAX);
    }

    scanf("%d", &N);

    star_recursive(0, 0, N, true);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%c", (star_map[i][j]?'*':' '));
        }
        printf("\n");
    }

    return 0;
}
