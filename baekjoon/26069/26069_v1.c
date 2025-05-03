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

int hashing(char* name)
{
    int i;
    int mapping_num = 0, name_len = strlen(name);

    for(i = name_len - 1; i >= 0; i--)
    {
        mapping_num *= 62;
        mapping_num += (int)(name[i]);
        mapping_num %= HASH_SIZE;
    }

    return mapping_num;
}

bool is_already_hashing(char* name, int hash_num)
{
    int base = hash_num;

    while(true)
    {
        if(!strcmp(hashinfo[hash_num].name, name))
        {
            return true;
        }

        hash_num = (hash_num + 1) % HASH_SIZE;

        if(hash_num == base)
        {
            return false;
        }
    }
}

int name_hashing(char *name, int hash_num)
{
    while(strlen(hashinfo[hash_num].name) != 0)
    {
        hash_num = (hash_num + 1) % HASH_SIZE;
    }

    strcpy(hashinfo[hash_num].name, name);
}

int main(void)
{
    int i;
    int N, hash_1, hash_2, dance_count = 1;
    char get_string_1[NAME_MAX], get_string_2[NAME_MAX];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s %s", get_string_1, get_string_2);

        hash_1 = hashing(get_string_1);
        if(is_already_hashing(get_string_1, hash_1) == false)
        {
            name_hashing(get_string_1, hash_1);
        }

        hash_2 = hashing(get_string_2);
        if(is_already_hashing(get_string_2, hash_2) == false)
        {
            name_hashing(get_string_2, hash_2);
        }
        if(!strcmp(BASE_NAME, get_string_1))
        {
            hashinfo[hash_1].isdance = true;
        }
        else if(!strcmp(BASE_NAME, get_string_2))
        {
            hashinfo[hash_2].isdance = true;
        }

        if(hashinfo[hash_1].isdance && !hashinfo[hash_2].isdance)
        {
            hashinfo[hash_2].isdance = true;
            dance_count++;
        }
        else if(hashinfo[hash_2].isdance && !hashinfo[hash_1].isdance)
        {
            hashinfo[hash_1].isdance = true;
            dance_count++;
        }
    }

    printf("%d\n", dance_count);

    return 0;
}
