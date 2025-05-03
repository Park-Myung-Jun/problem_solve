#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BASE_NAME "ChongChong"
#define HASH_SIZE 3003
#define NAME_MAX 21

typedef struct _tsHashInfo {
    char name[NAME_MAX];
    bool isdance;
} tsHashInfo;

tsHashInfo hashinfo[HASH_SIZE] = {0};

int hashing_get_value(char c)
{
    if('0' <= c && c <= '9')
    {
        return (int)(c - '0' + 1);
    }
    else if('A' <= c && c <= 'Z')
    {
        return (int)(c - 'A' + 11);
    }
    else if('a' <= c && c <= 'z')
    {
        return (int)(c - 'a' + 37);
    }
}

int hashing(char* name)
{
    int i;
    int mapping_num = 0, name_len = strlen(name);

    for(i = 0; i < name_len; i++)
    {
        mapping_num = (mapping_num * 63) % HASH_SIZE;
        mapping_num += (int)(hashing_get_value(name[i]));
    }

    //printf("map %d\n", mapping_num);

    return mapping_num;
}

int hashing_mapping(char* name)
{
    int base = hashing(name);

    while(hashinfo[base].name[0] != '\0')
    {
        base = (base + 1) % HASH_SIZE;
    }

    return base;
}

bool hashing_find(char *name, int* value)
{
    int base = hashing(name);

#if 0
    if(hashinfo[base].name[0] == '\0')
    {
        return false;
    }
#endif

    while(strcmp(hashinfo[base].name, name))
    {
        if(hashinfo[base].name[0] == '\0')
        {
            return false;
        }

        base = (base + 1) % HASH_SIZE;
#if 0
        // if(base == origin)
        if(hashinfo[base].name[0] == '\0')
        {
            return false;
        }
#endif
    }

    *value = base;
    return true;
}

int main(void)
{
    int i;
    int N, hash_1, hash_2, dance_count = 1;
    int hash_value_1, hash_value_2;
    char get_string_1[NAME_MAX], get_string_2[NAME_MAX];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        memset(get_string_1, 0x00, sizeof(char) * NAME_MAX);
        memset(get_string_2, 0x00, sizeof(char) * NAME_MAX);

        scanf("%s %s", get_string_1, get_string_2);

        if(!hashing_find(get_string_1, &hash_value_1))
        {
            hash_value_1 = hashing_mapping(get_string_1);
            strcpy(hashinfo[hash_value_1].name, get_string_1);
        }

        if(!hashing_find(get_string_2, &hash_value_2))
        {
            hash_value_2 = hashing_mapping(get_string_2);
            strcpy(hashinfo[hash_value_2].name, get_string_2);
        }

        if(!strcmp(get_string_1, BASE_NAME))
        {
            hashinfo[hash_value_1].isdance = true;
        }
        else if(!strcmp(get_string_2, BASE_NAME))
        {
            hashinfo[hash_value_2].isdance = true;
        }

        if(hashinfo[hash_value_1].isdance == true)
        {
            if(hashinfo[hash_value_2].isdance == false)
            {
                dance_count++;
                hashinfo[hash_value_2].isdance = true;
            }
        }
        else if(hashinfo[hash_value_2].isdance == true)
        {
            if(hashinfo[hash_value_1].isdance == false)
            {
                dance_count++;
                hashinfo[hash_value_1].isdance = true;
            }
        }

        //printf("%s %d %s %d\n", get_string_1, hash_value_1, get_string_2, hash_value_2);
    }

    printf("%d\n", dance_count);

    return 0;
}
