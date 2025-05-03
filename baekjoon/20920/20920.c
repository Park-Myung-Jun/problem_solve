#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define WORD_MAX_SIZE 100000
#define WORD_MAX_LENGTH 11
#define HASH_SIZE 203003

typedef struct _tsWord {
    char string[WORD_MAX_LENGTH];
    int count;
    int length;
} tsWord;

typedef struct _tsHashInfo {
    char string[WORD_MAX_LENGTH];
    int index;
} tsHashInfo;

tsWord word[WORD_MAX_SIZE] = {0};
int word_count = 0;

tsHashInfo word_hash_table[HASH_SIZE] = {0};

int hashing_get_value(char c)
{
    if('a' <= c && c <= 'z')
    {
        return (int)(c - 'a' + 1);
    }
}

int hashing(char* string)
{
    int i;
    int mapping_num = 0, string_len = strlen(string);

    for(i = 0; i < string_len; i++)
    {
        mapping_num = (mapping_num * 27) % HASH_SIZE;
        mapping_num += (int)(hashing_get_value(string[i]));
    }

    return mapping_num;
}

bool word_find(char* string, int* index, int word_count)
{
    int base = hashing(string);

    while(strcmp(word_hash_table[base].string, string))
    {
        base = (base + 1) % HASH_SIZE;

        if(word_hash_table[base].string[0] == '\0')
        {
            strcpy(word_hash_table[base].string, string);
            word_hash_table[base].index = word_count;
            return false;
        }
    }

    *index = word_hash_table[base].index;
    return true;
}

int algo_function(const void* p_a, const void* p_b)
{
    tsWord a = *(tsWord*)p_a;
    tsWord b = *(tsWord*)p_b;

    if(a.count != b.count)
    {
        return (a.count < b.count) - (a.count > b.count);
    }
    else if(a.length != b.length)
    {
        return (a.length < b.length) - (a.length > b.length);
    }

    return strcmp(a.string, b.string);
}

int main(void)
{
    int i, j;
    int N, M;
    int word_length, index;
    char word_get[WORD_MAX_LENGTH];

    scanf("%d %d", &N, &M);

    for(i = 0; i < N; i++)
    {
        memset(word_get, 0x00, sizeof(char) * WORD_MAX_LENGTH);
        scanf("%s", word_get);
        word_length = strlen(word_get);

        //printf("%s %d\n", word_get, word_length);

        if(word_length < M)
        {
            continue;
        }

        if(!word_find(word_get, &index, word_count))
        {
            strcpy(word[word_count].string, word_get);
            word[word_count].count = 1;
            word[word_count].length = strlen(word_get);
            word_count++;
        }
        else
        {
            word[index].count++;
        }
    }

    qsort(word, word_count, sizeof(tsWord), algo_function);

    for(i = 0; i < word_count; i++)
    {
        //printf("%s %d %d\n", word[i].string, word[i].count, word[i].length);
        printf("%s\n", word[i].string);
    }

    return 0;
}
