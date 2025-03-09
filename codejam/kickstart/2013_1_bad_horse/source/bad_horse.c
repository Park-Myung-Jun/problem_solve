#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 64
#define GRAPH_MAX_SIZE 101
#define QUEUE_SIZE 101

#define USE_LOG 0

typedef struct _tsGraphNode
{
    char* str;
    int num;
} tsGraphNode;

typedef enum _tePointType
{
    POINT_TYPE_NONE,
    POINT_TYPE_A,
    POINT_TYPE_B,
} tePointType;

tsGraphNode relation[QUEUE_SIZE] = {0};
int relation_size = 0;

int relation_graph[GRAPH_MAX_SIZE][GRAPH_MAX_SIZE] = {0};
int relation_point[GRAPH_MAX_SIZE] = {0};
bool is_divisable = true;

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

void BFS_Start(int start)
{
    int queue[QUEUE_SIZE] = {0};
    int rear = 0;
    int front = 0;

    queue[rear] = start;
    relation_point[start] = POINT_TYPE_A;
    rear = (rear + 1) % QUEUE_SIZE;

    while((rear + 1) % QUEUE_SIZE != front)
    {
        int now = queue[front];
        front = (front + 1) % QUEUE_SIZE;

#if USE_LOG
        printf("now %d type %d\n", now, relation_point[now]);
#endif

        for(int i = 0; i < GRAPH_MAX_SIZE; i++)
        {
            if(relation_graph[now][i])
            {
#if USE_LOG
                printf("connect %d type %d\n", i, relation_point[i]);
#endif
                if(relation_point[now] == POINT_TYPE_A)
                {
                    if(relation_point[i] == POINT_TYPE_A)
                    {
                        is_divisable = false;
                        return;
                    }
                    else if(relation_point[i] == POINT_TYPE_NONE)
                    {
                        relation_point[i] = POINT_TYPE_B;
                        queue[rear] = i;
                        rear = (rear + 1) % QUEUE_SIZE;
                    }
                }
                else if(relation_point[now] == POINT_TYPE_B)
                {
                    if(relation_point[i] == POINT_TYPE_B)
                    {
                        is_divisable = false;
                        return;
                    }
                    else if(relation_point[i] == POINT_TYPE_NONE)
                    {
                        relation_point[i] = POINT_TYPE_A;
                        queue[rear] = i;
                        rear = (rear + 1) % QUEUE_SIZE;
                    }
                }
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
        relation_size = 0;
        is_divisable = true;
        memset(relation_point, 0x00, sizeof(int) * GRAPH_MAX_SIZE);
        for(int i = 0; i < GRAPH_MAX_SIZE; i++)
        {
            memset(relation_graph[i], 0x00, sizeof(int) * GRAPH_MAX_SIZE);
        }

        scanf("%d", &M);

        for(int i = 0; i < M; i++)
        {
            scanf("%s %s", str_input1, str_input2); //printf("%s %s\n", str_input1, str_input2);

            int a = relation_check(str_input1);
            int b = relation_check(str_input2);

            relation_graph[a][b] = 1;
            relation_graph[b][a] = 1;
        }

#if USE_LOG
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
#endif

        for(int i = 0; i < relation_size; i++)
        {
            if(relation_point[i] == POINT_TYPE_NONE)
            {
                BFS_Start(i);
            }
        }

        if(is_divisable)
        {
            printf("Case #%d: Yes\n", t);
        }
        else
        {
            printf("Case #%d: No\n", t);
        }
    }

    for(int i = 0; i < relation_size; i++)
    {
        free(relation[i].str);
    }

    return 0;
}