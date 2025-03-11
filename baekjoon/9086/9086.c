#include <stdio.h>
#include <string.h>

#define STRING_BUFFER_SIZE 1001

int main(void)
{
    char string_buffer[STRING_BUFFER_SIZE];
    int T, string_len;

    scanf("%d", &T);
    while(T--)
    {
        memset(string_buffer, 0x00, STRING_BUFFER_SIZE);
        scanf("%s", string_buffer);
        string_len = strlen(string_buffer);
        printf("%c%c\n", string_buffer[0], string_buffer[string_len - 1]);
    }

    return 0;
}