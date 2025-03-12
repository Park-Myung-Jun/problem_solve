#include <stdio.h>
#include <string.h>

#define WHITE_PAPER_SIZE 100
#define BLACK_PAPER_SIZE 10

void stick_black_paper(char paper[][WHITE_PAPER_SIZE], int y, int x)
{
    int i, j;
    for(i = y; i < y + BLACK_PAPER_SIZE; i++)
    {
        for(j = x; j < x + BLACK_PAPER_SIZE; j++)
        {
            paper[i][j] = 1;
        }
    }
}

int find_black_area(char paper[][WHITE_PAPER_SIZE])
{
    int i, j;
    int black_area_size = 0;

    for(i = 0; i < WHITE_PAPER_SIZE; i++)
    {
        for(j = 0; j < WHITE_PAPER_SIZE; j++)
        {
            if(paper[i][j] == 1)
            {
                black_area_size++;
            }
        }
    }

    return black_area_size;
}

int main(void)
{
    int i, j;
    int n, x, y;
    char white_paper[WHITE_PAPER_SIZE][WHITE_PAPER_SIZE];

    for(i = 0; i < WHITE_PAPER_SIZE; i++)
    {
        memset(white_paper[i], 0x00, WHITE_PAPER_SIZE);
    }

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);

        stick_black_paper(white_paper, y, x);
    }

    printf("%d\n", find_black_area(white_paper));

    return 0;
}