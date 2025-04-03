#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DATA_STRUCTURE_MAX 100001

bool data_structure_type[DATA_STRUCTURE_MAX];
int data_structure[DATA_STRUCTURE_MAX], data_structure_front, data_structure_rear;

int main(void)
{
    int i;
    int N, M, get_num, tmp;

    scanf("%d", &N);

    memset(data_structure_type, 0x00, sizeof(bool) * DATA_STRUCTURE_MAX);
    memset(data_structure, 0x00, sizeof(int) * DATA_STRUCTURE_MAX);
    data_structure_front = 0;
    data_structure_rear = 0;

    for(i = 0; i < N; i++)
    {
        scanf("%d", data_structure_type + i);
    }
    for(i = 0; i < N; i++)
    {
        scanf("%d", &get_num);

        if(data_structure_type[i] == false)
        {
            data_structure[data_structure_front] = get_num;
            data_structure_front = (data_structure_front + 1) % DATA_STRUCTURE_MAX;
        }
    }

    scanf("%d", &M);
    for(i = 0; i < M; i++)
    {
        scanf("%d", &get_num);
        data_structure[(data_structure_rear - 1 + DATA_STRUCTURE_MAX) % DATA_STRUCTURE_MAX] = get_num;
        data_structure_rear = (data_structure_rear - 1 + DATA_STRUCTURE_MAX) % DATA_STRUCTURE_MAX;

        printf("%d ", data_structure[(data_structure_front - 1 + DATA_STRUCTURE_MAX) % DATA_STRUCTURE_MAX]);
        data_structure_front = (data_structure_front - 1 + DATA_STRUCTURE_MAX) % DATA_STRUCTURE_MAX;
    }
    printf("\n");

    return 0;
}
