#include <stdio.h>
#include <string.h>

#define STRING_MAX_LINE 5
#define STRING_MAX_LENGTH 16

int main(void)
{
    int i, j;
    char string_buffer[STRING_MAX_LINE][STRING_MAX_LENGTH];
    for(i = 0; i < STRING_MAX_LINE; i++)
    {
        memset(string_buffer[i], 0x00, STRING_MAX_LENGTH * sizeof(char));
        scanf("%s", string_buffer[i]);
    }

    for(i = 0; i < STRING_MAX_LENGTH; i++)
    {
        for(j = 0; j < STRING_MAX_LINE; j++)
        {
            if(string_buffer[j][i] != '\0')
            {
                printf("%c", string_buffer[j][i]);
            }
        }
    }

    return 0;
}