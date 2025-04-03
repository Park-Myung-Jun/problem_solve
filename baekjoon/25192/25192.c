#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define LOG_MAX 21
#define CHARACTER_ALL 62

typedef struct _tsTrie {
    int enter_count;
    struct _tsTrie* character[CHARACTER_ALL];
} tsTrie;

int get_index(char character)
{
    if('0' <= character && character <= '9')
    {
        return (int)(character - '0');
    }
    else if('A' <= character && character <= 'Z')
    {
        return (int)(10 + character - 'A');
    }
    else if('a' <= character && character <= 'z')
    {
        return (int)(36 + character - 'a');
    }

    return 0;
}

void trie_input(tsTrie* p_trie, char* p_log, int p_enter_count)
{
    int i;
    int log_len = strlen(p_log), index;
    tsTrie* trie_position = p_trie;

    for(i = 0; i < log_len; i++)
    {
        index = get_index(p_log[i]);

        //printf("%u %c %d %u\n", trie_position, p_log[i], index, trie_position->character[index]);

        if(trie_position->character[index] == NULL)
        {
            trie_position->character[index] = (tsTrie*)calloc(1, sizeof(tsTrie));
            //rintf("%u\n", trie_position);
        }

        trie_position = trie_position->character[index];
    }

    trie_position->enter_count = p_enter_count;
}

bool trie_find(tsTrie* p_trie, char* p_log, int p_enter_count)
{
    int i;
    int log_len = strlen(p_log), index;
    tsTrie* trie_position = p_trie;

    for(i = 0; i < log_len; i++)
    {
        index = get_index(p_log[i]);

        //printf("%c %d %u\n", p_log[i], index, trie_position->character[index]);

        if(trie_position->character[index] == NULL)
        {
            //printf("find f\n");
            return false;
        }
        else
        {
            trie_position = trie_position->character[index];
        }
    }

    //printf("find t\n");
    if(p_enter_count != trie_position->enter_count)
    {
        return false;
    }

    return true;
}

int main(void)
{
    int i;
    int N, count, enter_count;
    char log[LOG_MAX];
    tsTrie trie;

    count = 0;
    enter_count = 0;
    memset(log, 0x00, sizeof(char) * LOG_MAX);
    memset(&trie, 0x00, sizeof(tsTrie));

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s", log);
        //printf("%s\n", log);

        if(strcmp("ENTER", log))
        {
            if(trie_find(&trie, log, enter_count) == false)
            {
                trie_input(&trie, log, enter_count);
                count++;
            }
        }
        else
        {
            enter_count++;
        }
    }

    printf("%d\n", count);

    // Need free....

    return 0;
}
