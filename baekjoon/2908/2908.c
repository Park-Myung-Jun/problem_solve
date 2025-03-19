#include <stdio.h>
#include <string.h>

#define DIGIT_STRING_MAX 4

void string_reverse(char* str)
{
    int i, str_length = strlen(str);
    int str_length_half = str_length / 2;

    for(i = 0; i < str_length_half; i++)
    {
        if(str[i] != str[str_length - i - 1])
        {
            str[i] ^= str[str_length - i - 1];
            str[str_length - i - 1] ^= str[i];
            str[i] ^= str[str_length - i - 1];
        }
    }
}

int main(void)
{
    int i;
    char num_1[DIGIT_STRING_MAX], num_2[DIGIT_STRING_MAX];
    memset(num_1, 0x00, DIGIT_STRING_MAX * sizeof(char));
    memset(num_2, 0x00, DIGIT_STRING_MAX * sizeof(char));

    scanf("%s %s", num_1, num_2);

    for(i = DIGIT_STRING_MAX - 2; i >= 0; i--)
    {
        if(num_1[i] > num_2[i])
        {
            string_reverse(num_1);
            printf("%s\n", num_1);
            break;
        }
        else if(num_1[i] < num_2[i])
        {
            string_reverse(num_2);
            printf("%s\n", num_2);
            break;
        }
    }

    return 0;
}
