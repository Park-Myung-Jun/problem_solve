#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#define POKETMON_MAX 100000
#define POKETMON_NAME_MAX 21
#define ALPHA_ALL_MAX 52

typedef struct _tsPoketmon {
    int num;
    char name[POKETMON_NAME_MAX];
} tsPoketmon;

tsPoketmon poketmon[POKETMON_MAX];
tsPoketmon poketmon_seq_num[POKETMON_MAX];

int alpha_mapping(char character)
{
    if('a' <= character && character <= 'z')
    {
        return (int)(character - 'a');
    }
    else
    {
        return (int)(26 + character - 'A');
    }
}

int algo_function(const void* a, const void* b)
{
    return strcmp(((tsPoketmon*)a)->name, ((tsPoketmon*)b)->name);
}

int main(void)
{
    int i;
    int N, M;
    char get_string[POKETMON_NAME_MAX];

    scanf("%d %d", &N, &M);

    for(i = 0; i < N; i++)
    {
        poketmon[i].num = i + 1;
        poketmon_seq_num[i].num = i + 1;
        scanf("%s", poketmon[i].name);
        memcpy(poketmon_seq_num[i].name, poketmon[i].name, sizeof(char) * POKETMON_NAME_MAX);
    }

    qsort(poketmon, N, sizeof(tsPoketmon), algo_function);

#if 0
    for(int i = 0; i < N; i++)
    {
        printf("%s %d\n", poketmon[i].name, poketmon[i].num);
    }
#endif

    for(i = 0; i < M; i++)
    {
        memset(get_string, 0x00, sizeof(char) * POKETMON_NAME_MAX);

        scanf("%s", get_string);
        if('0' <= get_string[0] && get_string[0] <= '9')
        {
            printf("%s\n", poketmon_seq_num[atoi(get_string) - 1].name);
        }
        else
        {
            tsPoketmon tmp = {0}, *ptr;

            strcpy(tmp.name, get_string);
            ptr = bsearch(&tmp, poketmon, N, sizeof(tsPoketmon), algo_function);

            printf("%d\n", ptr->num);
        }
    }

    return 0;
}
