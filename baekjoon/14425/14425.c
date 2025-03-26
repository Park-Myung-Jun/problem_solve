#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING_NUM_MAX 10000
#define STRING_SIZE_MAX 501

char letters[STRING_NUM_MAX][STRING_SIZE_MAX];
char letters_check[STRING_NUM_MAX][STRING_SIZE_MAX];

int q_function(const void* a, const void* b)
{
    return strcmp(a, b);
}

int main(void)
{
    int i, j;
    int N, M, match_count;

    for(i = 0; i < STRING_NUM_MAX; i++)
    {
        memset(letters[i], 0x00, sizeof(char) * STRING_SIZE_MAX);
        memset(letters_check[i], 0x00, sizeof(char) * STRING_SIZE_MAX);
    }

    match_count = 0;

    scanf("%d %d", &N, &M);

    for(i = 0; i < N; i++)
    {
        scanf("%s", letters[i]);
    }

    qsort(letters, N, sizeof(char) * STRING_SIZE_MAX, q_function);

#if 0
    for(i = 0; i < N; i++)
    {
        printf("%s\n", letters[i]);
    }
#endif

    for(i = 0; i < M; i++)
    {
        scanf("%s", letters_check[i]);

        if(bsearch(letters_check[i], letters, N, sizeof(char) * STRING_SIZE_MAX, q_function) != NULL)
        {
            match_count++;
        }
    }

    printf("%d\n", match_count);

    return 0;
}
