#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPAHBET_MAX 26
#define STRING_MAX 101

int main(void)
{
    int i, j;
    int N, word_string_length, group_count;
    int alpha_data[ALPAHBET_MAX];
    char word_string[STRING_MAX];
    char alphabet_before;
    bool is_group = false;

    group_count = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        memset(alpha_data, 0x00, ALPAHBET_MAX * sizeof(int));

        scanf("%s", word_string);
        word_string_length = strlen(word_string);

        for(j = 0; j < word_string_length; j++)
        {
            if(j == 0)
            {
                is_group = true;
                alpha_data[word_string[j] - 'a']++;
                alphabet_before = word_string[j];
                continue;
            }

            if(alphabet_before != word_string[j])
            {
                if(alpha_data[word_string[j] - 'a'] != 0)
                {
                    is_group = false;
                    break;
                }

                alphabet_before = word_string[j];
            }

            alpha_data[word_string[j] - 'a']++;
        }

        if(is_group == true)
        {
            group_count++;
        }
    }

    printf("%d\n", group_count);

    return 0;
}
