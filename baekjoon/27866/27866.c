#include <stdio.h>

#define WORD_MAX_SIZE 1001

int main(void)
{
    char S[WORD_MAX_SIZE];
    int pos;

    scanf("%s %d", S, &pos);

    printf("%c\n", S[pos - 1]);

    return 0;
}