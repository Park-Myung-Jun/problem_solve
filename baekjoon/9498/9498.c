#include <stdio.h>

int main(void)
{
    char grade[] = {'A', 'B', 'C', 'D'};
    int score;

    scanf("%d", &score);

    if(score == 100)
    {
        printf("A\n");
    }
    else if(60 <= score)
    {
        printf("%c\n", grade[(99 - score) / 10]);
    }
    else
    {
        printf("F\n");
    }

    return 0;
}