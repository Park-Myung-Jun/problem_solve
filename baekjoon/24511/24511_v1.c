#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DATA_STRUCTURE_MAX 100000

bool data_structure_type[DATA_STRUCTURE_MAX];
int data_structure[DATA_STRUCTURE_MAX];

int main(void)
{
    int i, j;
    int N, M, get_num, tmp;

    scanf("%d", &N);

    memset(data_structure_type, 0x00, sizeof(bool) * DATA_STRUCTURE_MAX);
    memset(data_structure, 0x00, sizeof(int) * DATA_STRUCTURE_MAX);

    for(i = 0; i < N; i++)
    {
        scanf("%d", data_structure_type + i);
    }
    for(i = 0; i < N; i++)
    {
        scanf("%d", data_structure + i);
    }

    scanf("%d", &M);
    for(i = 0; i < M; i++)
    {
        scanf("%d", &get_num);

        for(j = 0; j < N; j++)
        {
            if(data_structure_type[j] == false)
            {
                tmp = data_structure[j];
                data_structure[j] = get_num;
                get_num = tmp;
            }
        }

        printf("%d ", get_num);
    }

    return 0;
}
