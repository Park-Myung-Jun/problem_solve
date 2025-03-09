#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 64
#define GRAPH_MAX_SIZE 101
#define UNION_SIZE 101

typedef struct _tsGraphNode
{
    char* str;
    int num;
} tsGraphNode;

tsGraphNode relation[UNION_SIZE] = {0};
int relation_size = 0;

int relation_graph[GRAPH_MAX_SIZE][GRAPH_MAX_SIZE] = {0};
int relation_union[GRAPH_MAX_SIZE] = {0};
int relation_visit[GRAPH_MAX_SIZE] = {0};
bool is_cycle = false;

int relation_check(char* str_input)
{
    for(int i = 0; i < relation_size; i++)
    {
        if(!strcmp(relation[i].str, str_input))
        {
            return i;
        }
    }

    relation[relation_size].str = (char*)malloc(sizeof(char) * (strlen(str_input) + 1));
    strcpy(relation[relation_size].str, str_input);
    relation[relation_size].num = relation_size;
    relation_size++;

    return relation_size - 1;
}

void find_cycle(int before, int now)
{
    relation_visit[now] = true;

    if(before != now)
    {
        relation_union[now] = relation_union[before];
    }

    for(int i = 0; i < relation_size; i++)
    {
        if(i == before)
        {
            continue;
        }

        if(relation_graph[now][i] == 1)
        {
            if(relation_union[now] == relation_union[i])
            {
                is_cycle = true;
                return;
            }

            find_cycle(now, i);

            if(is_cycle)
            {
                return;
            }
        }
    }
}

int main(void)
{
    int T = 0, M = 0, t = 0;
    char str_input1[BUFFER_SIZE] = {0}, str_input2[BUFFER_SIZE] = {0};
    scanf("%d", &T);

    for(t = 1; t <= T; t++)
    {
        for(int i = 0; i < UNION_SIZE; i++)
        {
            relation_union[i] = i;
            relation_visit[i] = false;
        }
        is_cycle = false;
        relation_size = 0;

        scanf("%d", &M);

        for(int i = 0; i < M; i++)
        {
            scanf("%s %s", str_input1, str_input2);
            //printf("%s %s\n", str_input1, str_input2);

            int a = relation_check(str_input1);
            int b = relation_check(str_input2);

            relation_graph[a][b] = 1;
            relation_graph[b][a] = 1;
        }

#if 0
        printf("relation size %d\n", relation_size);

        for(int i = 0; i < relation_size; i++)
        {
            printf("%s %d\n", relation[i].str, relation[i].num);
        }

        for(int i = 0; i < relation_size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                printf("%d ", relation_graph[i][j]);
            }

            printf("\n");
        }

        for(int i = 0; i < relation_size; i++)
        {
            free(relation[i].str);
        }
#endif

        for(int i = 0; i < relation_size; i++)
        {
            if(!relation_visit[i])
            {
                find_cycle(i, i);
            }

            if(is_cycle)
            {
                break;
            }
        }

#if 0
        for(int i = 0; i < relation_size; i++)
        {
            printf("%d %d\n", relation_union[i], relation_visit[i]);
        }
#endif

        if(is_cycle)
        {
            printf("Case #%d: No\n", t);
        }
        else
        {
            printf("Case #%d: Yes\n", t);
        }
    }

    return 0;
}