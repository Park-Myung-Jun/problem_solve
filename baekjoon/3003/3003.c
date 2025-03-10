#include <stdio.h>
#include <string.h>

#define CHESS_UINT_SIZE 6

int main(void)
{
    int chess_base[CHESS_UINT_SIZE] = {1, 1, 2, 2, 2, 8};
    int chess_piece[CHESS_UINT_SIZE];
    int i;

    memset(chess_piece, 0x00, CHESS_UINT_SIZE * sizeof(int));

    for(i = 0; i < CHESS_UINT_SIZE; i++)
    {
        scanf("%d", chess_piece + i);
    }

    for(i = 0; i < CHESS_UINT_SIZE; i++)
    {
        printf("%d ", chess_base[i] - chess_piece[i]);
    }
    printf("\n");

    return 0;
}