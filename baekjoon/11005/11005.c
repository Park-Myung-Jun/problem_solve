#include <stdio.h>
#include <string.h>

#define DIGIT_STRING_MAX 30

int main(void)
{
    int N, B;
    char digit_string[DIGIT_STRING_MAX];
    int digit_count = 0;
    int i, digit_string_len;

    memset(digit_string, 0x00, DIGIT_STRING_MAX * sizeof(char));
    scanf("%d %d", &N, &B);

    if(N == 0)
    {
        digit_string[0] = '0';
    }

    while(N != 0)
    {
        int rest = N % B;
        if(rest < 10)
        {
            digit_string[digit_count] = rest + '0';
        }
        else
        {
            digit_string[digit_count] = rest - 10 + 'A';
        }

        digit_count++;

        N /= B;
    }

    digit_string_len = strlen(digit_string);
    for(i = 0; i < digit_string_len / 2; i++)
    {
        char tmp = digit_string[i];
        digit_string[i] = digit_string[digit_string_len - i - 1];
        digit_string[digit_string_len - i - 1] = tmp;
    }

    printf("%s\n", digit_string);

    return 0;
}