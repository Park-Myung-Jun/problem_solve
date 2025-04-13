#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 500000
#define NAME_LENGTH_MAX 21

char name[NAME_MAX][NAME_LENGTH_MAX];
char name2[NAME_MAX][NAME_LENGTH_MAX];
int name2_count = 0;

int algo_function(const void* p_a, const void* p_b)
{
    return strcmp(p_a, p_b);
}

int main(void)
{
    int i;
    int N, M;
    char* name_ptr = NULL, get_string[NAME_LENGTH_MAX];

    scanf("%d %d", &N, &M);

    for(i = 0; i < NAME_MAX; i++)
    {
        memset(name[i], 0x00, sizeof(char) * NAME_LENGTH_MAX);
        memset(name2[i], 0x00, sizeof(char) * NAME_LENGTH_MAX);

        if(i < N)
        {
            scanf("%s", name[i]);
        }
    }

    qsort(name, N, sizeof(char) * NAME_LENGTH_MAX, algo_function);

    for(i = 0; i < M; i++)
    {
        memset(get_string, 0x00, NAME_LENGTH_MAX);
        name_ptr = NULL;

        scanf("%s", get_string);

        name_ptr = bsearch(get_string, name, N, sizeof(char) * NAME_LENGTH_MAX, algo_function);

        if(name_ptr != NULL)
        {
            //printf("%s\n", get_string);
            strcpy(name2[name2_count], get_string);
            name2_count++;
        }
    }

    qsort(name2, name2_count, sizeof(char) * NAME_LENGTH_MAX, algo_function);

    printf("%d\n", name2_count);
    for(i = 0; i < name2_count; i++)
    {
        printf("%s\n", name2[i]);
    }

    return 0;
}
