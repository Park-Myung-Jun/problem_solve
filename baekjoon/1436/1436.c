#include <stdio.h>
#include <string.h>

#define DIGIT_MAX 16
#define NUM_MAX 10000000000
#define NUM_FIND "666"
#define NUM_FIND_SIZE 3

int main(void)
{
    int i, j;
    int N, count, string_strlen;
    char string_buffer[DIGIT_MAX];

    scanf("%d", &N);
    count = 0;
    i = 666;

    while(i < NUM_MAX)
    {
        memset(string_buffer, 0x00, DIGIT_MAX * sizeof(char));
        sprintf(string_buffer, "%d", i);

        string_strlen = strlen(string_buffer) + 1 - NUM_FIND_SIZE;
        for(j = 0; j < string_strlen; j++)
        {
            if(!strncmp(string_buffer + j, NUM_FIND, NUM_FIND_SIZE))
            {
                //printf("%s\n", string_buffer);
                count++;
                break;
            }
        }

        if(count == N)
        {
            printf("%s\n", string_buffer);
            break;
        }

        i++;
    }

    return 0;
}
