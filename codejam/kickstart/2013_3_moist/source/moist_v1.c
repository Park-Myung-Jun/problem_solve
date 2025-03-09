#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 101
#define TOKEN_VALUE " "
#define USE_LOG 0

void change_str(char* dst, char* src, char* tmp)
{
#if USE_LOG
    printf("tmp %s dst %s src %s\n", tmp, dst, src);
#endif

    memcpy(tmp, dst, NAME_MAX);
    memcpy(dst, src, NAME_MAX);
    memcpy(src, tmp, NAME_MAX);

#if USE_LOG
    printf("tmp %s dst %s src %s\n", tmp, dst, src);
#endif
}

int main(void)
{
    int T, t, N;
    int i, position;
    int cmp_result, cmp_result_2, cost;
    char* token = NULL;

    char card_name[NAME_MAX][2][NAME_MAX] = {0};
    char card_get_name[NAME_MAX] = {0};
    char temporary_card[NAME_MAX] = {0};

    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        cost = 0;
        memset(temporary_card, 0x00, NAME_MAX);
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

        // check
        for(i = 1; i < N; i++)
        {
            printf("%d %s %s\n", i, card_name[i - 1][0], card_name[i][0]);
            cmp_result = strcmp(card_name[i - 1][0], card_name[i][0]);

            if(!cmp_result)
            {
                cmp_result = strcmp(card_name[i - 1][1], card_name[i][1]);

                if(0 < cmp_result_2)
                {
                    change_str(card_name[i - 1][0], card_name[i][0], temporary_card);
                    change_str(card_name[i - 1][1], card_name[i][1], temporary_card);

#if 0
                    memcpy(temporary_card, card_name[i][0], NAME_MAX);
                    memcpy(temporary_card, card_name[i][1], NAME_MAX);

                    memcpy(card_name[i][0], card_name[i - 1][0], NAME_MAX);
                    memcpy(card_name[i][1], card_name[i - 1][1], NAME_MAX);

                    memcpy(card_name[i - 1][0], temporary_card, NAME_MAX);
                    memcpy(card_name[i - 1][1], temporary_card, NAME_MAX);
#endif

                    printf("%s %s <> %s %s, %d, %d\n",
                        card_name[i - 1][0], card_name[i - 1][1],
                        card_name[i][0], card_name[i][1],
                        cmp_result, cmp_result_2);

                    i = 0;
                    cost++;
                }
            }
            else if(0 < cmp_result)
            {
                change_str(card_name[i - 1][0], card_name[i][0], temporary_card);
                change_str(card_name[i - 1][1], card_name[i][1], temporary_card);

                printf("%s %s <> %s %s, %d, %d\n",
                    card_name[i - 1][0], card_name[i - 1][1],
                    card_name[i][0], card_name[i][1],
                    cmp_result, cmp_result_2);

                i = 0;
                cost++;
            }
        }

        printf("Case #%d: %d\n", t, cost);
    }

    return 0;
}