#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_MAX 6
#define NAME_ARRAY_SIZE 100000

char name_array[NAME_ARRAY_SIZE][BUFFER_MAX];

int algo_function(const void* a, const void* b)
{
    return strcmp(a, b);
}

int main(void)
{
    int i;
    int n, name_array_count;
    char get_string_name[BUFFER_MAX];
    char get_string_log[BUFFER_MAX];

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        memset(name_array[i], 0x00, sizeof(char) * BUFFER_MAX);
    }
    memset(get_string_name, 0x00, sizeof(char) * BUFFER_MAX);
    memset(get_string_log, 0x00, sizeof(char) * BUFFER_MAX);
    name_array_count = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%s %s", get_string_name, get_string_log);

        strcpy(name_array[name_array_count], get_string_name);
        name_array_count++;
    }

    qsort(name_array, name_array_count, sizeof(char) * BUFFER_MAX, algo_function);

    for(i = name_array_count - 1; i >= 0; i--)
    {
        if((i - 1 >= 0) && (!strcmp(name_array[i], name_array[i - 1])))
        {
            i--;
        }
        else
        {
            printf("%s\n", name_array[i]);
        }
    }

    return 0;
}
