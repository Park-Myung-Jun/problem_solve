#include <stdio.h>
#include <string.h>

#define STRING_MAX_SIZE 103003
#define STRING_MAX_LENGTH 21
#define HASH_VALUE 103003

typedef struct _tsPair {
    char site[STRING_MAX_LENGTH];
    char password[STRING_MAX_LENGTH];
} tsPair;

tsPair pair[STRING_MAX_SIZE] = {0};

int char_mapping(char c)
{
    if('a' <= c && c <= 'z')
    {
        return (int)(c - 'a' + 1);
    }
    else if('A' <= c && c <= 'Z')
    {
        return (int)(c - 'A' + 27);
    }
    else if('-')
    {
        return 53;
    }
    else if('.')
    {
        return 54;
    }
}

int hashing_find_value(char* string)
{
    int i, str_len = strlen(string), ret = 0;

    for(i = 0; i < str_len; i++)
    {
        ret = (ret * 55) % HASH_VALUE;
        ret += char_mapping(string[i]);
    }

    //printf("ret %d\n", ret);

    return ret;
}

int hashing_input(char* string)
{
    int ret = hashing_find_value(string);

    while(pair[ret].site[0] != '\0')
    {
        ret = (ret + 1) % HASH_VALUE;
    }

    return ret;
}

int hashing_find(char* string)
{
    int ret = hashing_find_value(string);

    while(strcmp(pair[ret].site, string))
    {
        ret = (ret + 1) % HASH_VALUE;
    }

    return ret;
}

int main(void)
{
    int i;
    int N, M, hashing_value;
    char get_string_site[STRING_MAX_LENGTH], get_string_password[STRING_MAX_LENGTH];

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++)
    {
        memset(get_string_site, 0x00, sizeof(char) * STRING_MAX_LENGTH);
        memset(get_string_password, 0x00, sizeof(char) * STRING_MAX_LENGTH);

        scanf("%s %s", get_string_site, get_string_password);

        hashing_value = hashing_input(get_string_site);

        strcpy(pair[hashing_value].site, get_string_site);
        strcpy(pair[hashing_value].password, get_string_password);

        //printf("%d %s %s\n", hashing_value, pair[hashing_value].site, pair[hashing_value].password);
    }

    for(i = 0; i < M; i++)
    {
        memset(get_string_site, 0x00, sizeof(char) * STRING_MAX_LENGTH);

        scanf("%s", get_string_site);

        hashing_value = hashing_find(get_string_site);

        //printf("%d %s\n", hashing_value, pair[hashing_value].password);
        printf("%s\n", pair[hashing_value].password);
    }

    return 0;
}
