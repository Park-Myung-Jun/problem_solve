#include <stdio.h>
#include <string.h>

#define EDGE_MAX_SIZE 50
#define CHESS_EDGE_SIZE 8

int chess_check_wb(char map[][EDGE_MAX_SIZE + 1], int y, int x)
{
    int i, j, count = 0;
    char color[2] = {'W', 'B'};

    for(i = y; i < y + CHESS_EDGE_SIZE; i++)
    {
        for(j = x; j < x + CHESS_EDGE_SIZE; j++)
        {
            if(map[i][j] != color[(i + j) % 2])
            {
                count++;
            }
        }
    }

    return count;
}

int chess_check_bw(char map[][EDGE_MAX_SIZE + 1], int y, int x)
{
    int i, j, count = 0;
    char color[2] = {'B', 'W'};

    for(i = y; i < y + CHESS_EDGE_SIZE; i++)
    {
        for(j = x; j < x + CHESS_EDGE_SIZE; j++)
        {
            if(map[i][j] != color[(i + j) % 2])
            {
                count++;
            }
        }
    }

    return count;
}

int main(void)
{
    int i, j;
    int N, M, count_min = CHESS_EDGE_SIZE * CHESS_EDGE_SIZE, get_check_count;
    char chess_map[EDGE_MAX_SIZE][EDGE_MAX_SIZE + 1];

    scanf("%d %d", &N, &M);

    for(i = 0; i < EDGE_MAX_SIZE; i++)
    {
        memset(chess_map[i], 0x00, (EDGE_MAX_SIZE + 1) * sizeof(char));
        scanf("%s", chess_map[i]);
    }

    for(i = 0; i < N - CHESS_EDGE_SIZE + 1; i++)
    {
        for(j = 0; j < M - CHESS_EDGE_SIZE + 1; j++)
        {
            get_check_count = chess_check_wb(chess_map, i, j);
            if(get_check_count < count_min)
            {
                count_min = get_check_count;
            }

            get_check_count = chess_check_bw(chess_map, i, j);
            if(get_check_count < count_min)
            {
                count_min = get_check_count;
            }
        }
    }

    printf("%d\n", count_min);

    return 0;
}
