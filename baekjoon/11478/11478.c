#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_LENGTH_MAX 1001

char substring[STRING_LENGTH_MAX][STRING_LENGTH_MAX] = {0};

int algo_function(const void* a, const void* b)
{
    return strcmp(a, b);
}

int main(void)
{
    int i, j;
    char get_string[STRING_LENGTH_MAX], tmp_string[STRING_LENGTH_MAX];
    int get_string_length;
    int diff_count = 0;

    memset(get_string, 0x00, sizeof(char) * STRING_LENGTH_MAX);

    scanf("%s", get_string);
    get_string_length = strlen(get_string);

    for(i = 0; i < get_string_length; i++)
    {
        for(j = 0; j < get_string_length - i; j++)
        {
            memset(substring[j], 0x00, sizeof(char) * STRING_LENGTH_MAX);

            strncpy(substring[j], get_string + j, i + 1);
        }

#if 0
        for(j = 0; j < get_string_length - i; j++)
        {
            printf("%s\n", substring[j]);
        }
        printf("\n");
#endif

        qsort(substring, get_string_length - i, sizeof(char) * STRING_LENGTH_MAX, algo_function);

        memset(tmp_string, 0x00, sizeof(char) * STRING_LENGTH_MAX);

        for(j = 0; j < get_string_length - i; j++)
        {
            //printf("%s\n", substring[j]);

            if(strcmp(tmp_string, substring[j]))
            {
                strcpy(tmp_string, substring[j]);
                diff_count++;
            }
        }
    }

    printf("%d\n", diff_count);

    return 0;
}
