#include <stdio.h>
#include <string.h>

#define DIGIT_MAX 32

int digit_to_num(char alpha)
{
    if('0' <= alpha && alpha <= '9')
    {
        return (int)(alpha -'0');
    }
    else if('A' <= alpha && alpha <= 'Z')
    {
        return (int)(alpha - 'A' + 10);
    }
}

int main(void)
{
    int i;
    int B, digit_length, result;
    char N[DIGIT_MAX];

    memset(N, 0x00, sizeof(char) * DIGIT_MAX);
    scanf("%s %d", N, &B);

    result = 0;
    digit_length = strlen(N);
    for(i = 0; i < digit_length; i++)
    {
        result = result * B + digit_to_num(N[i]);
    }

    printf("%d\n", result);

    return 0;
}