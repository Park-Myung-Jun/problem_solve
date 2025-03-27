#include <stdio.h>

#define EDGE_COUNT_SIZE 3

int main(void)
{
    int i, j;
    int tmp;
    int edge[EDGE_COUNT_SIZE];

    for(i = 0; i < EDGE_COUNT_SIZE; i++)
    {
        scanf("%d", edge + i);
    }

    for(i = 0; i < 2; i++)
    {
        for(j = i + 1; j < 3; j++)
        {
            if(edge[i] > edge[j])
            {
                tmp = edge[i];
                edge[i] = edge[j];
                edge[j] = tmp;
            }
        }
    }

    if(edge[0] + edge[1] > edge[2])
    {
        printf("%d\n", edge[0] + edge[1] + edge[2]);
    }
    else
    {
        printf("%d\n", (edge[0] + edge[1]) * 2 - 1);
    }

    return 0;
}
