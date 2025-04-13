#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define POKETMON_MAX 100000
#define POKETMON_NAME_MAX 20
#define ALPHA_ALL_MAX 52

typedef struct _tsTri {
    int num;
    struct _tsTri* next[ALPHA_ALL_MAX];
} tsTri;

typedef struct _tsPoketmon {
    char name[POKETMON_NAME_MAX];
} tsPoketmon;

tsPoketmon poketmon[POKETMON_MAX];
tsTri tri;

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

void tri_push(char* name, int num)
{
    int i, name_len = strlen(name);
    tsTri* position = &tri;

    for(i = 0; i < name_len; i++)
    {
        if(position->next[alpha_mapping(name[i])] == NULL)
        {
            position->next[alpha_mapping(name[i])] = (tsTri*)calloc(1, sizeof(tsTri));
        }
        position = position->next[alpha_mapping(name[i])];
        //printf("%c %u ", name[i], position);
    }
    //printf("%d\n", num);

    position->num = num;
}

int tri_find(char* name)
{
    int i, name_len = strlen(name);
    tsTri* position = &tri;

    for(i = 0; i < name_len; i++)
    {
        position = position->next[alpha_mapping(name[i])];
        //printf("%c %u ", name[i], position);
    }
    //printf("%d\n", position->num);

    return position->num;
}

int main(void)
{
    int i;
    int N, M;
    char get_string[POKETMON_NAME_MAX];

    scanf("%d %d", &N, &M);

    memset(&tri, 0x00, sizeof(tsTri));

    for(i = 0; i < N; i++)
    {
        scanf("%s", poketmon[i].name);
        tri_push(poketmon[i].name, i + 1);
    }

    for(i = 0; i < M; i++)
    {
        memset(get_string, 0x00, sizeof(char) * POKETMON_NAME_MAX);

        scanf("%s", get_string);
        if('0' <= get_string[0] && get_string[0] <= '9')
        {
            printf("%s\n", poketmon[atoi(get_string) - 1].name);
        }
        else
        {
            printf("%d\n", tri_find(get_string));
        }
    }

    return 0;
}
