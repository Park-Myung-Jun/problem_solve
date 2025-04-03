#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_MAX_SIZE 20000
#define WORD_MAX_LENGTH 51

int algo_function(const void* a, const void* b)
{
    int compre_length = (strlen(a) > strlen(b)) - (strlen(a) < strlen(b));

    if(compre_length != 0)
    {
        return compre_length;
    }
    else
    {
        return strcmp(a, b);
    }
}

int main(void)
{
    int i;
    int N;
    char word[WORD_MAX_SIZE][WORD_MAX_LENGTH];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        memset(word[i], 0x00, sizeof(char) * WORD_MAX_LENGTH);
        scanf("%s", word[i]);
    }

    qsort(word, N, sizeof(char) * WORD_MAX_LENGTH, algo_function);

    for(i = 0; i < N; i ++)
    {
        if(0 < i)
        {
            if(strcmp(word[i - 1], word[i]))
            {
                printf("%s\n", word[i]);
            }
        }
        else
        {
            printf("%s\n", word[i]);
        }
    }

    return 0;
}
