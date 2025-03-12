#include <stdio.h>
#include <string.h>

#define STRING_MAX_SIZE 101

int isPalindrome(char* string)
{
    int i, str_len;
    str_len = strlen(string);

    for(i = 0; i < str_len / 2; i++)
    {
        if(string[i] != string[str_len - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    char get_string[STRING_MAX_SIZE];

    memset(get_string, 0x00, STRING_MAX_SIZE);

    scanf("%s", get_string);

    printf("%d\n", isPalindrome(get_string));

    return 0;
}