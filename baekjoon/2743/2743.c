#include <stdio.h>
#include <string.h>

#define STRING_BUFFER_SIZE 101

int main(void)
{
    char string_buffer[STRING_BUFFER_SIZE];

    memset(string_buffer, 0x00, STRING_BUFFER_SIZE * sizeof(char));

    scanf("%s", string_buffer);

    printf("%d\n", strlen(string_buffer));

    return 0;
}