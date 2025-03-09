#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 101
#define TOKEN_VALUE " "
#define USE_LOG 0

void change_str(char* dst, char* src, char* tmp)
{
    memcpy(tmp, dst, NAME_MAX);
    memcpy(dst, src, NAME_MAX);
    memcpy(src, tmp, NAME_MAX);
}

int main(void)
{
    int T, t, N;
    int i, position;
    int cmp_result, cmp_result_2, cost;
    char* token = NULL;

    char card_name[NAME_MAX][2][NAME_MAX] = {0};
    char card_get_name[NAME_MAX] = {0};
    char card_base[2][NAME_MAX] = {0};
    char card_temporary[NAME_MAX] = {0};

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        cost = 0;
        memset(card_temporary, 0x00, NAME_MAX);
        memset(card_base[0], 0x00, NAME_MAX);
        memset(card_base[1], 0x00, NAME_MAX);
        memset(card_name, 0x00, NAME_MAX * 2 * NAME_MAX);
        scanf("%d", &N);

        //printf("%d %d\n", T, N);
        //fflush(stdin); // not recommanded, instread next
        while(getchar() != '\n')
        {
            continue;
        }

        for(i = 0; i < N; i++)
        {
            memset(card_get_name, 0x00, NAME_MAX);
            fgets(card_get_name, NAME_MAX, stdin);
            card_get_name[strlen(card_get_name) - 1] = '\0';
            //printf("%s\n", card_get_name);

            position = 0;
            token = strtok(card_get_name, TOKEN_VALUE);
            while (token)
            {
                //printf("%s\n", token);
                memcpy(card_name[i][position], token, strlen(token));
                position++;
                token = strtok(NULL, TOKEN_VALUE);
            }
        }

#if USE_LOG
        for(i = 0; i < N; i++)
        {
            printf("%s %s\n", card_name[i][0], card_name[i][1]);
        }
#endif

        // set base(first)
        // check 1~N
        // if not lexicographical, count++,
        // else change set base,

        strcpy(card_base[0], card_name[0][0]);
        strcpy(card_base[1], card_name[0][1]);

        for(i = 1; i < N; i++)
        {
            cmp_result = strcmp(card_base[0], card_name[i][0]);

            if(!cmp_result)
            {
                cmp_result_2 = strcmp(card_base[1], card_name[i][1]);

                if(0 > cmp_result_2)
                {
                    change_str(card_base[0], card_name[i][0], card_temporary);
                    change_str(card_base[1], card_name[i][1], card_temporary);
                }
                else
                {
                    cost++;
                }
            }
            else if(0 > cmp_result)
            {
                change_str(card_base[0], card_name[i][0], card_temporary);
                change_str(card_base[1], card_name[i][1], card_temporary);
            }
            else
            {
                cost++;
            }
        }

        printf("Case #%d: %d\n", t, cost);
    }

    return 0;
}