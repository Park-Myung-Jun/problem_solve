#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STRING_MAX_SIZE 1000001
#define ALPHABET_MAX_SIZE 26

int main(void)
{
    int i;
    int word_string_len, alphabet_array[ALPHABET_MAX_SIZE];
    int alphabet_num_max, alphabet_num_max_count, alphabet_num_max_index;
    char word_string[STRING_MAX_SIZE];

    alphabet_num_max = 0;
    alphabet_num_max_count = 0;
    alphabet_num_max_index = 0;
    memset(word_string, 0x00, STRING_MAX_SIZE * sizeof(char));
    memset(alphabet_array, 0x00, ALPHABET_MAX_SIZE * sizeof(int));

    scanf("%s", word_string);
    word_string_len = strlen(word_string);
    for(i = 0; i < word_string_len; i++)
    {
        if('a' <= word_string[i] && word_string[i] <= 'z')
        {
            alphabet_array[word_string[i] - 'a']++;
        }
        else if('A' <= word_string[i] && word_string[i] <= 'Z')
        {
            alphabet_array[word_string[i] - 'A']++;
        }
    }

    for(i = 0; i < ALPHABET_MAX_SIZE; i++)
    {
        if(alphabet_num_max < alphabet_array[i])
        {
            alphabet_num_max = alphabet_array[i];
        }
    }

    for(i = 0; i < ALPHABET_MAX_SIZE; i++)
    {
        if(alphabet_num_max == alphabet_array[i])
        {
            alphabet_num_max_count++;
            alphabet_num_max_index = i;
        }
    }

    //printf("%d %d %d\n", alphabet_num_max, alphabet_num_max_count, alphabet_num_max_index);

    if(alphabet_num_max_count == 1)
    {
        printf("%c\n", (char)(alphabet_num_max_index + 'A'));
    }
    else
    {
        printf("?\n");
    }

    return 0;
}