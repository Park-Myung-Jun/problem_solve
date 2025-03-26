#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USE_LOG 0

#define BUFFER_MAX 6
#define NAME_HASH_SIZE 100000

int name_hash[NAME_HASH_SIZE];

int Name_to_Hash(char* string)
{
    int i, hash = 0;
    int string_len = strlen(string);

    for(i = string_len - 1; i >= 0; i--)
    {
        hash *= 53;

        if('a' <= string[i] && string[i] <= 'z')
        {
            hash += (string[i] - 'a' + 1);
        }
        else if('A' <= string[i] && string[i] <= 'Z')
        {
            hash += (string[i] - 'A' + 27);
        }
    }

    return hash;
}

void Hash_to_Name(int hash, char* string)
{
    int i = 0;
    int num;
    char alphabet;

    while(hash != 0)
    {
        num = hash % 53;
        if(1 <= num && num <= 26)
        {
            alphabet = (char)(num - 1 + 'a');
        }
        else if(27 <= num && num <= 52)
        {
            alphabet = (char)(num - 27 + 'A');
        }

        string[i] = alphabet;
        hash /= 53;
        i++;
    }
}

int algo_function(const void* a, const void* b)
{
    int left = *(const int*)a;
    int right = *(const int*)b;

    return (left < right) - (left > right);
}

int main(void)
{
    int i;
    int n, name_hash_size = 0, bsearch_key;
    char get_string_name[BUFFER_MAX];
    char get_string_log[BUFFER_MAX];

    scanf("%d", &n);
    memset(name_hash, 0x00, NAME_HASH_SIZE * sizeof(int));
    memset(get_string_name, 0x00, sizeof(char) * BUFFER_MAX);
    memset(get_string_log, 0x00, sizeof(char) * BUFFER_MAX);

    for(i = 0; i < n; i++)
    {
        scanf("%s %s", get_string_name, get_string_log);

#if USE_LOG
        printf("%s %s\n", get_string_name, get_string_log);

        name_hash[name_hash_size] = Name_to_Hash(get_string_name);
        printf("%d\n", name_hash[name_hash_size]);

        memset(get_string_name, 0x00, sizeof(char) * BUFFER_MAX);
        Hash_to_Name(name_hash[name_hash_size], get_string_name);
        printf("%s\n", get_string_name);
#endif

        if(get_string_log[0] == 'e')
        {
            name_hash[name_hash_size] = Name_to_Hash(get_string_name);
            name_hash_size++;

            qsort(name_hash, name_hash_size, sizeof(int), algo_function);
        }
        else if(get_string_log[0] == 'l')
        {
            bsearch_key = Name_to_Hash(get_string_name);
            name_hash[((int*)bsearch(&bsearch_key, name_hash, name_hash_size, sizeof(int), algo_function) - name_hash)] = 0;
            qsort(name_hash, name_hash_size, sizeof(int), algo_function);
            name_hash_size--;
        }
    }

    for(i = 0; i < name_hash_size; i++)
    {
        memset(get_string_name, 0x00, sizeof(char) * BUFFER_MAX);
        Hash_to_Name(name_hash[i], get_string_name);
        printf("%s\n", get_string_name);
    }

    return 0;
}
